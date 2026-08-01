class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build the weighted graph

        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto time: times){
            int u = time[0];
            int v = time[1];
            int weight = time[2];
            graph[u].push_back({v, weight});
        }
        // initialize the reach time vector, besides the starting node (=0), all other nodes is INF
        vector<int> reach_time(n + 1, INT_MAX);
        reach_time[k] = 0;

        // put the source into a min heap
        // {shortest distance from k, node}
        priority_queue<pair<int, int>, 
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()){
            // pop the current queue
            auto [currTime, node] = pq.top();
            pq.pop();
            // ignore the old, inferior heap entry
            if (currTime > reach_time[node]) continue;

            // start relaxation
            for (auto [neighbor, weight]: graph[node]){
                int newTime = currTime + weight;
                if (newTime < reach_time[neighbor]){
                    reach_time[neighbor] = newTime;
                    pq.push({newTime, neighbor});

                }
            }

        }

        // return the maximum time amount all the reach time
        int maxTime = -1;
        for (int node = 1; node <= n; node++) {
            if (reach_time[node] == INT_MAX) {
                return -1;
            }

            maxTime = max(maxTime, reach_time[node]);
        }

        return maxTime;

    }
};
