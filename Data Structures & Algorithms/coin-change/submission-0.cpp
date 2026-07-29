class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[x]: the minimum number of coins needed to make amount x
        // dp[x] = min(dp[x], 1 + dp[x - coin])

        vector<int> dp(amount + 1, amount + 1);
        // base case: zero amount requires 0 coin
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++){
            for (auto coin: coins){
                // check whether there will be out of bound
                int ind = i - coin;
                if (ind < 0) continue;
                else{
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // if the number is never updated, then that number is impossible
        return dp[amount] == amount + 1? -1: dp[amount];
    }
};
