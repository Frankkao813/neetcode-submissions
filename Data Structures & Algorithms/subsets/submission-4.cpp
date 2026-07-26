class Solution {
private:
    vector<int> curr;
    vector<vector<int>> result;
    void backtrack(vector<int> nums, int index){
        if (index >= nums.size()){
            result.push_back(curr);
            return;
        }

        // select the curr element
        curr.push_back(nums[index]);
        backtrack(nums, index + 1);
        curr.pop_back();
        backtrack(nums, index + 1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};
