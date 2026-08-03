class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] = number of ways that is unique
        // dp[i][j] = dp[i][j-1] + dp[i - 1][j]
        // dp[0][0..n] = 1 dp[0..m][0] = 1
    
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
