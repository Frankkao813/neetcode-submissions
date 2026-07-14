class Solution {
private:
    void bfsHelper(vector<vector<bool>>& visited, vector<vector<int>>& heights, queue<std::pair<int, int>> q){
        vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = heights.size();
        int n = heights[0].size();
        while (!q.empty()) {
            auto [currRow, currCol] = q.front();
            q.pop();

            for (auto [dRow, dCol] : dirs) {
                int newRow = currRow + dRow;
                int newCol = currCol + dCol;

                bool inBoundary =
                    newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n;

                if (
                    inBoundary &&
                    !visited[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[currRow][currCol]
                ) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        // BFS from the pacific ocean
        // add the first row and the first column index into the queue
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<std::pair<int, int>> q;
        for (int i = 0; i < n; i++){
            q.push({0, i});
            pacific[0][i] = true;
        }
        
        // prevent adding (0, 0) twice
        for (int j = 1; j < m; j++){
            q.push({j, 0});
            pacific[j][0] = true;
        }

        queue<std::pair<int, int>> q_atlantic;
        for (int i = 0; i < n; i++){
            q_atlantic.push({m-1, i});
            atlantic[m-1][i] = true;
        }
        // prevent adding (m - 1, n - 1) twice
        for (int j = 0; j < m-1; j++){
            q_atlantic.push({j, n-1});
            atlantic[j][n - 1] = true;
        }

        bfsHelper(pacific, heights,  q);
        bfsHelper(atlantic, heights,  q_atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++){
            for (int j = 0; j <n; j++){
                if (pacific[i][j] == true && atlantic[i][j] == true){
                    result.push_back({i, j});
                }
            }
        }

        return result;
        
        

    }
};
