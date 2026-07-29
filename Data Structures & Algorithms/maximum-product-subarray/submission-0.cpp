class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // maxProd[i]: maximum product of an array ending at i
        // minProd[i]: minimum product of an array ending at i

        int n = nums.size();
        vector<int> minProd(n, 101);
        vector<int> maxProd(n, -101);
        minProd[0] = nums[0];
        maxProd[0] = nums[0];
        int result = nums[0]; // store the maximum element at this moment

        // start the bottom-up DP
        for (int i = 1; i < n; i++){
            minProd[i] = min({nums[i], minProd[i - 1] * nums[i], maxProd[i - 1] * nums[i]});
            maxProd[i] = max({nums[i], minProd[i-1] * nums[i], maxProd[i-1] * nums[i]});
            result = max(result, maxProd[i]);
        }


        return result;


    }
};
