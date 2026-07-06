class Solution {
public:
    void sortColors(vector<int>& nums) {
        // close to selection sort style
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (nums[i] > nums[j]){
                    std::swap(nums[i], nums[j]);
                }
            }
        }
    }
};