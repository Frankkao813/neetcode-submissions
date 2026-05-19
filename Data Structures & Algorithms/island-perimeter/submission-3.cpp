class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // connected island
        int rows = grid.size();
		int cols = grid[0].size();
        std::pair<int, int> start;
        vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 1){
                    start = {i, j};
                    break;
                }
            }
        }

        // prevent us from going to the same col
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[start.first][start.second] = true;

        queue<std::pair<int, int>> q;
        q.push(start);

        int perimeter = 0;
        while (!q.empty()){
            auto [currRow, currCol] = q.front();
            q.pop();
            for (auto [deltaRow, deltaCol] : directions) {
                int newRow = currRow + deltaRow;
                int newCol = currCol + deltaCol;

                // out of bounds means exposed edge
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    perimeter++;
                }
                // water means exposed edge
                else if (grid[newRow][newCol] == 0) {
                    perimeter++;
                }
                // unvisited land means continue BFS
                else if (grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
            
        }
        return perimeter;
    }
};