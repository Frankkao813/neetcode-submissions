class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // use the same method we encountered in merge intervals
        // add the newInterval into the intervals
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (const auto& curr: intervals){
            // There is no overlap
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
