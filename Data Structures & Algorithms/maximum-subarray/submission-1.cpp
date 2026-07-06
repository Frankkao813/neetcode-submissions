class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dynamic programming based method
        // dp[i] = max(extend to running sum, start new from here)
        // dp[0] = first element
        int n = nums.size();
        vector<int> dp(n, 0);
        // base case
        dp[0] = nums[0];
        for (int i = 1; i  < n; i++){
            dp[i] = max(nums[i] + dp[i-1], nums[i]);
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
