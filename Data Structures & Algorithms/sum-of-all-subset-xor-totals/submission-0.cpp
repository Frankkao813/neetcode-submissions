class Solution {
private:
    int total = 0;
    void backtrack(vector<int>& nums, int i, int currXor){
        if (i == nums.size()){
            total += currXor;
            return;
        }

        // possibility 1: choose nums[i]
        backtrack(nums, i + 1, currXor ^ nums[i]);

        // possibility 2: don't choose nums[i]
        backtrack(nums, i + 1, currXor);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return total;
    }
};