class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // use the same method we encountered in merge intervals
        // add the newInterval into the intervals

        intervals.push_back(newInterval);
        // sort the interval
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++){
            if (result.empty() || result.back()[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }

        }
        return result;

    }
};
