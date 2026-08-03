class Solution {
public:
    int jump(vector<int>& nums) {
        // dynamic programming
        // dp[i]: minimum number of steps to reach i
        // transition: From index i, you can reach every index from i + 1 through i + nums[i]
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            // check if this cell is reachable
            if (dp[i] == INT_MAX) continue;
            int step = nums[i];
            for (int j = 0; j <= step && i + j < n; j++){
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }

        return dp[n-1];
    }
};
