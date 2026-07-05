class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // hash map
        std::unordered_map<int, int> numCnt;

        for (int num: nums){
            numCnt[num]++;
        }
        int threshold = nums.size()/2;
        for (auto [num, cnt]: numCnt){
            if (cnt > threshold){
                return num;
            }
        }

        return -1; // should not exist
    }
};