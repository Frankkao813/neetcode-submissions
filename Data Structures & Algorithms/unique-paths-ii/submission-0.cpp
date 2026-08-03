class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // the path is still dp[i][j] = dp[i-1][j] + dp[i][j-1]
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }

        // check if we can start from the start
        if (obstacleGrid[0][0] == 1) return 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                } 

                // Avoid updating the starting cell again.
                if (i == 0 && j == 0) {
                    continue;
                }
                
                // i - 1 < 0 -> No path coming from that cell
                int valTop = (i > 0)? dp[i-1][j] : 0;
                int valLeft = (j > 0)? dp[i][j-1] : 0;
                dp[i][j] = valTop + valLeft;
            }
        }   

        return dp[m-1][n-1];


    }
};