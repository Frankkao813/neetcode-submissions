class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int j = 0; // track the left boundary
        for (int num: nums){
            // check if there is already same element in the window
            if (window.count(num)){
                return true;
            }

            window.insert(num);

            if (window.size() > k){
                window.erase(nums[j]);
                j++;
            }
        }

        return false;
    }
};