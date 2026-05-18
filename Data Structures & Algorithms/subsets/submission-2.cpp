class Solution {
private:
    vector<vector<int>> result;
    vector<int> curr;
    void subsetHelper(vector<int>& nums, int pos){

        for (int i = pos; i < nums.size(); i++){
            // choose
            curr.push_back(nums[i]);
            result.push_back(curr);
            // explore
            subsetHelper(nums, i + 1);
            // backtrack
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        subsetHelper(nums, 0); // {vector, int}
        return result;
    }
};
