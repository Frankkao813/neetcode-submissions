class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // initialize indegree and adjacency list
        vector<int> indegree(numCourses, 0);
        // The adjacency list stores the prereq -> course relationship
        vector<vector<int>>adjlist (numCourses);
        for (vector<int> prereq: prerequisites){
            int course = prereq[0];
            int pre = prereq[1];
            indegree[course]++;
            adjlist[pre].push_back(course);
        }

        // initialize the queue - add all vertices with zero indegree to queue
        // so that they have no dependencies
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        int courseTaken = 0;
        while (!q.empty()){
            // dequeue from the front vertex
            int course = q.front();
            q.pop();
            courseTaken++;
            for (int nextCourse: adjlist[course]){
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }

        }

        return courseTaken == numCourses;
    }
};
