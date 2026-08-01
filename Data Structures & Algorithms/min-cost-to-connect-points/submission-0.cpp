class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // cheapest edge from the current MST to node i.
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        // start from point 0
        minDist[0] = 0;
        int totalCost = 0;
        for (int count = 0; count < n; count++){
            int curr = -1;
            for (int i = 0; i < n; i++){
                // consider point i it is hasn't been added to MST AND
                // Choose i if we have not chosen any candidate yet, or if i is cheaper than the current candidate.
                if (!visited[i] && (curr == -1 || minDist[i] < minDist[curr])){
                    curr = i;
                }
            }

            // add to MST
            visited[curr] = true;
            totalCost += minDist[curr];

            // update the neighbor
            for (int next = 0; next < n; next++){
                if (!visited[next]){
                    int distance = abs(points[curr][0] - points[next][0]) + abs(points[curr][1] - points[next][1]);
                    minDist[next] = min(minDist[next], distance);
                }
            }
            
        }

        return totalCost;

    }
};
