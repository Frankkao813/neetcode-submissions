class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       // M1: brute force - O(n^3)
       sort(nums.begin(), nums.end());
       set<vector<int>> uniqueTriplet;
       for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                for (int k = j + 1; k < nums.size(); k++){
                    if (nums[i] + nums[j] + nums[k] == 0){
                        uniqueTriplet.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
       } 

       vector<vector<int>> result(uniqueTriplet.begin(), uniqueTriplet.end());
       return result;
    }
};
