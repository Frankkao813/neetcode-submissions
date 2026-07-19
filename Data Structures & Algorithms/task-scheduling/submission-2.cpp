class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count the occurence
        vector<int> cnt(26, 0);
        int m = tasks.size();
        for (int i = 0; i < m; i++){
            cnt[tasks[i] - 'A']++;
        }

        // create the cooldown queue and the max heap
        priority_queue<int> pq;
        queue<pair<int, int>> cooldown; // {cnt, cooldown}
        for (int i = 0; i < 26; i++){
            if (cnt[i] > 0){
                pq.push(cnt[i]);
            }
        }

        // start the simulation 
        int time = 0;
        while (!pq.empty() || !cooldown.empty()){
            time++;
            // see what task in the queue can be added back
            if (!cooldown.empty() && cooldown.front().second <= time){
                auto curr = cooldown.front();
                cooldown.pop();
                pq.push(curr.first);
            }

            // process from the heap
            if (!pq.empty()){
                auto process = pq.top();
                pq.pop();
                process--;
                if (process > 0){
                    cooldown.push({process, time + n + 1});
                }

            }

        }

        return time;
    }
};
