class Solution {
private:
    vector<int> curr;
    vector<vector<int>> result;

    void backtrack(vector<int> nums, int index, int remaining){
        if (remaining == 0){
            result.push_back(curr);
            return;
        }

        if (remaining < 0 || index >= nums.size()){
            return;
        }

        // choose the element
        curr.push_back(nums[index]);
        backtrack(nums, index, remaining - nums[index]);
        // pop the element
        curr.pop_back();
        backtrack(nums, index + 1, remaining);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,0, target);
        return result;
    }
};
