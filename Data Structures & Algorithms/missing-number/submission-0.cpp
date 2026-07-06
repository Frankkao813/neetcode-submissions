class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // x ^ x = 0, x ^ 0 = x
        // XOR 0..n with all nums.
        // All existing numbers cancel out; missing number remains.

        int ans = 0;

        for (int i = 0; i <= nums.size(); i++) {
            ans ^= i;
        }

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};