class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       // M2: sorting + two pointer
        int n  = nums.size();
        set<vector<int>> uniqueNum;
       sort(nums.begin(), nums.end());
       for (int i = 0; i < nums.size() - 2; i++){
            int curr = i;
            int ptr1 = curr + 1;
            int ptr2 = n - 1;
            while (ptr1 < ptr2){
                int total = nums[i] + nums[ptr1] + nums[ptr2];
                if (total == 0){
                    uniqueNum.insert({nums[i], nums[ptr1], nums[ptr2]});
                    ptr1++;
                    ptr2--;
                }
                else if (total > 0){
                    ptr2--;
                }
                else {
                    ptr1++;
                }
                
            }
       }

       vector<vector<int>> result(uniqueNum.begin(), uniqueNum.end());

       return result;
    }
};
