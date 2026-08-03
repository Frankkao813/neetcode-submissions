class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> reachable(n, false);
        // the first cell is always reachable
        reachable[0] = true;
        for (int i = 0; i < n; i++){
            // check if the cell is reachable
            if (!reachable[i]) continue;

            int step = nums[i];
            for (int j = 0; j <= step && i + j < n; j++){
                // standing from i, jump to j steps forward.
                // j = 0, 1, ..., step
                reachable[i + j] = true;
            }
        }

        return reachable[n - 1];
    }
};
