class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // key idea: first sort the intervals by the  end
        // This method is simpler, for the earlier-ending interval is already kept

        // sort according to end time;
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]< b[1];
        });
        int removal = 0;
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            if (currStart < prevEnd){
                // Overlap: conceptually remove the interval, with the larger ending removed
                removal++;
            }
            else{
                // no overlap: keep the current interval
                prevEnd = currEnd;
            }
        }

        return removal;
    }
};
