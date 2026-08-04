class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // for each trip, one can add numPassengers to every location from from through to - 1:
        vector<int> passengers(1001, 0);
        for (vector<int> trip: trips){
            int passenger = trip[0];
            int from = trip[1];
            int to = trip[2];
            // The passenger is dropped off at to
            for (int i = from; i < to; i++){
                passengers[i] += passenger;
            }
        }
        for (int i = 1; i <= 1000; i++){
            if (passengers[i] > capacity){
                return false;
            }
        }

        return true;
    }
};