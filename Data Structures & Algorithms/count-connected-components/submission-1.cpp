class Solution {
private:
    bool dfs(int curr,vector<vector<int>>& graph, vector<bool>& visited){
        // no need for cycle detection, a connected component is allowed to have cycle
        visited[curr] = true;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }

        return true;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if (not n) return 0;
        // create adjacenecy list
        vector<vector<int>> graph(n);
        for (const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            else{
                dfs(i, graph, visited);
                count++;
            } 
        }

        return count;
        

    }
};
