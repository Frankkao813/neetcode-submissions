class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // method: two pointers
        int left = 0;
        int maxP = 0;
        int n = prices.size();
        for (int right = 1; right < n; right++){
            if (prices[left] < prices[right]){
                maxP = max(maxP, prices[right] - prices[left]);
            }
            else{
                left = right;
            }
        }

        return maxP;
    }
};
