class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        // Push the number vector two times
        for (int i = 0; i < 2; i++){
            for (int num: nums){
                result.push_back(num);
            }
        }

        return result;
    }
};