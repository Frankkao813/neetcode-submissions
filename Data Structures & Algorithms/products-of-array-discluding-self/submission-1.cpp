class Solution {
    // Idea: answer[i] = product of everything left i *
    // product of everything right i
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 1);
        vector<int> left(n, 1);
        vector<int> result(n, 1);
        // fill in left array
        for (int i = 0; i < n- 1; i++){
            left[i + 1] = left[i] * nums[i];
        }
        // fill in the right array
        for (int i = n-2; i >= 0; i--){
            right[i] = right[i + 1] * nums[i + 1];
        } 

        // populate the result array
        for (int i = 0; i < n; i++){
            result[i] = left[i] * right[i];
        }


        return result;

    }
};
