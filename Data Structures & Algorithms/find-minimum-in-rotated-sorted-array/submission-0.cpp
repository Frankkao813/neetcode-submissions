class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        // in rotated sorted array, each array has two increasing components
        // compare the medium element (one component) to the rightmost element (another component)
        while (left < right){
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else {
                //mid might be the minimum
                right = mid;
            }

        }

        // returning left or right doesn't matter. Since right ptr == left ptr
        return nums[left];

    }
};
