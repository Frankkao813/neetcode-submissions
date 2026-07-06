class Solution {
private:
    void dfsHelper(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        // check before accessing the grid
        if (i < 0 || i >= m || j < 0 || j >= n) return;

        // stop at water or already visited cell
        if (grid[i][j] == '0' || visited[i][j] == 1) return;

        visited[i][j] = 1;
        vector<std::pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        
        for (auto [u, v]: direction){
            dfsHelper(grid, visited, i + u, j + v);
        }

}
        
public:
    int numIslands(vector<vector<char>>& grid) {
        // approach: DFS

        
        queue<std::pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        // create a visited array
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    dfsHelper(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    
    }
};
