class Solution {
private:
    bool dfs(int curr, int parent, vector<vector<int>>& graph, vector<bool>& visited){
        // Visited through another path: cycle detected.
        if (visited[curr]) return false;
        visited[curr] = true;
        
        for (int node: graph[curr]){
            if (node == parent) continue;
            
            // continue to recurse
            if (!dfs(node, curr, graph, visited)) return false; 
        }
        // if we exit the loop without return false in the middle
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        vector<vector<int>> graph(n);
        for (const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);

        }
        vector<bool> visited(n, false);
        dfs(0, -1, graph, visited);

        // A tree must contain every node in one connected component.
        for (bool wasVisited : visited) {
            if (!wasVisited) {
                return false;
            }
        }

        return true;
    }
};