class Solution {
private:
    void bfsHelper(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        vector<std::pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<std::pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()){
            auto [u, v] = q.front();
            q.pop();
            for (auto [dirX, dirY]: direction){
                int newX = u + dirX;
                int newY = v + dirY;
                if (newX < 0 || newX >= m || newY < 0 || newY >= n){
                    continue;
                }
                else if (grid[newX][newY] == '1' && visited[newX][newY] == 0){
                    visited[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // approach: BFS

        
        queue<std::pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        // create a visited array
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    bfsHelper(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    
    }
};
