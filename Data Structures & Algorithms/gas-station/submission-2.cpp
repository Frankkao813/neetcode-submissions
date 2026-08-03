class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // M2: greedy
        int totalGas = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++){
            totalGas += gas[i] - cost[i];
        }
        if (totalGas < 0) return -1; // not possible

        // Pass 2: find the valid starting station.
        // When a candidate start fails, eliminate an entire range of impossible starting stations.
        int currGas = 0;
        int start = 0;
        for (int i = 0; i < n; i++){
            currGas += (gas[i] - cost[i]);
            if (currGas < 0){
                start = i + 1;
                currGas = 0;
            }
        }

        return start;
    }
};
