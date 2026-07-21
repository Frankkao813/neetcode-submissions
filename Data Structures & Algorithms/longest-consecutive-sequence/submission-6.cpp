class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // method: unordered_set
        unordered_set<int> numbers(nums.begin(), nums.end());
        int max_len = 0;
        for (int num: nums){
            // find if this number is the start
            if (numbers.find(num - 1) == numbers.end()){
                int len = 1;
                int curr = num;
                // continue to find the next consecutive number
                while (numbers.find(curr + 1) != numbers.end()){
                    len += 1;
                    curr += 1;
                }
                max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};
