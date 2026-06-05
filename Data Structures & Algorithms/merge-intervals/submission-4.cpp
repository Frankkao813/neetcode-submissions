class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first sort by the start
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){
            // custom comparator requires a strict order relationship
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;
        
        for (vector<int> interval: intervals){
            if (result.empty() || result.back()[1] < interval[0]){
                result.push_back(interval);
            }
            else{
                result.back()[1] = max(interval[1], result.back()[1]);
            }
        }
        return result;
    }
};
