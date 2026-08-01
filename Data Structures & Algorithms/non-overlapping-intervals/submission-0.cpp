class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // key idea: first sort the intervals by the start
        // when the two intervals overlap, we keep the one with the smaller end time

        // sort according to start time;
        std::sort(intervals.begin(), intervals.end());
        int removal = 0;
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            if (currStart < prevEnd){
                // Overlap: conceptually remove the interval, with the larger ending
                removal++;
                prevEnd = min(prevEnd, currEnd);
            }
            else{
                // no overlap: keep the current interval
                prevEnd = currEnd;
            }
        }

        return removal;
    }
};
