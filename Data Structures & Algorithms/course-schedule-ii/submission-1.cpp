class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's algorithm

        // first we find the indegree array and then the prereq -> course adjlist
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for (vector<int> prerequisite: prerequisites){
            int prereq = prerequisite[1];
            int course = prerequisite[0];
            indegree[course]++;
            adjList[prereq].push_back(course);
        }

        // push the the course where indegree = 0 into the queue
        queue<int> q;
        vector<int> order;
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            // The prerequisite node removed, so the indegree of the neighbor should be deducted by 1.
            for (int neighbor: adjList[curr]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return order.size() == numCourses? order: vector<int>{};
    }
};
