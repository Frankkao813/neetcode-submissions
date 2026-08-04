class Solution {
private:
    vector<int> curr;
    vector<vector<int>> result;

    void backtrack(vector<int> nums, int index, int remaining){
        if (remaining == 0){
            result.push_back(curr);
            return;
        } 
        if (remaining < 0 || index >= nums.size()) return;

        // start the recursion
        // path 1: we keep using the same number
        curr.push_back(nums[index]);
        backtrack(nums, index, remaining - nums[index]);
        curr.pop_back();
        // path 2: we stop using the number, and we use the next one 
        backtrack(nums, index + 1, remaining);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, target);
        return result;
    }
};
