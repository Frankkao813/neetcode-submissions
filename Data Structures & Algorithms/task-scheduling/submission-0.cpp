class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count the occurence
        vector<int> count(26, 0);
        for (char task: tasks){
            count[task - 'A']++;
        }

        // push the element into the maxHeap
        priority_queue<int> pq;
        queue<std::pair<int, int>> q; // {cnt, cooldown time}
        for (int i = 0; i < 26; i++){
            if (count[i] != 0){
                pq.push(count[i]);
            }
        }

        // start the simulation
        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            // release tasks whose cooldown is over
            while (!q.empty() && q.front().second <= time) {
                auto element = q.front();
                q.pop();
                pq.push(element.first);
            }

            // choose a task to run at this time
            // we can only let it run once, for the element will be put in the queue
            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if (cnt > 0) {
                    q.push({cnt, time + n + 1});
                }
            }
        }


        return time;
    }
};
