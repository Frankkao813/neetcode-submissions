class Solution {
public:
    vector<pair<int, int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++){; 
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int dist = 0;
        while (!q.empty()){
            dist++;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                auto [currRow, currCol] = q.front();
                q.pop();
                for (auto [dRow, dCol]: directions){
                    int newRow = currRow + dRow;
                    int newCol = currCol + dCol;
                    bool inside = newRow >= 0 && newRow < m && newCol >= 0 && newCol < n;
                    if (inside && grid[newRow][newCol] == 2147483647){
                        grid[newRow][newCol] = dist;
                        q.push({newRow, newCol});
                    }
                }
            }

        }   
    }
};
