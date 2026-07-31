class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        // record the healthy fruit count
        int healthy_cnt  = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1)
                    healthy_cnt++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // record the rotting fruit
        int day = 0;
        while (!q.empty() && healthy_cnt > 0){
            day++;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                auto [row, col] = q.front();
                q.pop();
                for (auto dir: directions){
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    bool inside = newRow >= 0 && newRow < m && newCol >= 0 && newCol < n;
                    if (inside && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        healthy_cnt--;
                    }
                }
            }

        }

        return healthy_cnt == 0? day: -1;
    }
};
