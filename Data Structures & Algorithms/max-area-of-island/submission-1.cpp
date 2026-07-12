class Solution {
private:
    int bfsHelper(vector<vector<int>>& grid, int row, int col){
        int m  = grid.size();
        int n = grid[0].size();
        std::vector<std::pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<std::pair<int, int>> q;

        // When visited, directly alter the content of the cell
        grid[row][col] = 0;
        q.push({row, col});
        int area = 0;
        while (!q.empty()){
            auto [row, col]  = q.front();
            q.pop();
            area++;
            for (auto [dRow, dCol]: dir){
                int newRow = row + dRow;
                int newCol = col + dCol;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1 ){
                        grid[newRow][newCol] = 0;
                        q.push({newRow, newCol});

                }
            }
        }

        return area;

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = 0;
        int col = 0;
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int curr = bfsHelper(grid, i, j);
                    maxArea = max(maxArea, curr);
                }
            }
        }

        return maxArea;
    }
};
