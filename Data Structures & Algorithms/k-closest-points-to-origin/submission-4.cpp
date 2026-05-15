class Solution {
    // method: max heap
    priority_queue<pair<int, vector<int>>> pq;
    int euclidean(int x, int y){
        return x * x + y * y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (auto point:points){
            int dist = euclidean(point[0], point[1]);
            pq.push({dist, point});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};
