class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr1 = 0; // write pointer
        int ptr2 = 0; //  read pointer
        int prev = -101;
        while (ptr2 < nums.size()){
            if (nums[ptr2] == prev){
                ptr2++;
            }
            else {
                nums[ptr1] = nums[ptr2];
                prev = nums[ptr2];
                ptr1++;
                ptr2++;
                
            }
        }
        return ptr1;
    }
};