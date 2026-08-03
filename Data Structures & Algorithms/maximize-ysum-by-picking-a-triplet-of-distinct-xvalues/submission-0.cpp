class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> best;
        for (int i = 0; i < x.size(); i++){
            int val = x[i];
            if (best.find(val) == best.end()){
                best[val] = y[i];
            }
            else {
                best[val] = max(y[i], best[val]);
            }
        }

        // see if there is three elements
        if (best.size() < 3) return -1;

        // try to get the largest 3 elements
        vector<int> values;
        for (auto [key, val]: best){
            values.push_back(val);
        }

        sort(values.rbegin(), values.rend());

        return values[0] + values[1] + values[2];
    }
};