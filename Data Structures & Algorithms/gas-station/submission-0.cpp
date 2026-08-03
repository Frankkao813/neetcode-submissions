class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // M1: brute force simulation
        int n = gas.size();
        vector<int> dp(n, INT_MAX);

        for (int start = 0 ; start < n; start++){
            int tank = 0;
            bool possible = true;
            for (int step = 0; step < n; step++){
                int curr = (start + step) % n;
                // adding and decreasing oil
                tank += gas[curr];
                tank -= cost[curr];
                if (tank < 0) possible = false;
            }
            if (possible) return start;
        }
        return -1;
    }
};
