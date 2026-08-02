class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the array by start
        std::sort(intervals.begin(), intervals.end());
        int i = 1;
        vector<vector<int>> result;
        for (const auto& curr: intervals){
            if (result.empty() || curr[0] > result.back()[1]){
                result.push_back(curr);
            }
            else{
                result.back()[1] = max(result.back()[1], curr[1]);
            }
        }

        return result;

    }
};
