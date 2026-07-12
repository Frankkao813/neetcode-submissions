class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Count fresh oranges and add all initially rotten oranges
        // as BFS starting points.
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                } else if (grid[row][col] == 1) {
                    freshOranges++;
                }
            }
        }

        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        int minutes = 0;

        while (!q.empty() && freshOranges > 0) {
            int levelSize = q.size();

            // Process one BFS level, representing one minute.
            for (int i = 0; i < levelSize; i++) {
                auto [currRow, currCol] = q.front();
                q.pop();

                for (auto [dRow, dCol] : directions) {
                    int newRow = currRow + dRow;
                    int newCol = currCol + dCol;

                    if (newRow >= 0 && newRow < m &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        q.push({newRow, newCol});
                    }
                }
            }

            minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};