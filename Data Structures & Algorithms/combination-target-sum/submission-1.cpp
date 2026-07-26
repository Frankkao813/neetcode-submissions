class Solution {
private:
    vector<int> curr;
    vector<vector<int>> result;

    void backtrack(vector<int> nums, int index, int remaining){
        if (remaining == 0){
            result.push_back(curr);
            return;
        }

        if (index >= nums.size() || remaining < 0){
            return;
        }

        curr.push_back(nums[index]); // add the element
        backtrack(nums, index, remaining - nums[index]); // explore

        curr.pop_back(); // pop the element
        backtrack(nums, index + 1, remaining); // explore


    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,0, target);
        return result;
    }
};
