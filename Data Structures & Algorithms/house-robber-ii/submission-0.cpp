class Solution {
public:
    int linearRob(vector<int>& nums, int start, int end) {
        // dp[i]: the maximum number that one can rob from 0 .. n
        // at a door, one can rob, but he can only rob the previous one -> dp[i] = nums[i] + dp[i - 2]
        // or he can skip the door -> dp[i] = dp[i-1]

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        } 

        return dp[end];

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        // two linear rob attempts to compare the best
        // reason: The first and last rooms are adjacent, so we can only select one.
        int num1 = linearRob(nums, 1, n-1);
        int num2 = linearRob(nums, 0, n-2);

        return max(num1, num2);
    }
};
