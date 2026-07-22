class Solution {
public:
    int search(vector<int>& nums, int target) {
        // in the find the minimum in the rotated sorted array, we want 
        // compare the mid with the rightmost element
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            // the left half is sorted, check left half firsr
            // == -> handle the one element case
            if (nums[left] <= nums[mid]){
                // target lies inside the sorted left half
                // region: [nums[left], nums[mid]), we already checked the mid
                if (nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            // right half is sorted
            // Target lies in (nums[mid], nums[right]]
            else{
                if (nums[mid]< target && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
                
            }
        }


        return -1;
    }
};
