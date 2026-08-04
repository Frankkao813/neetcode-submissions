class Solution {
public:
    string reorganizeString(string s) {
        // record the occurence of each character
        unordered_map<char, int> umap;
        for (char c: s){
            umap[c]++;
        }

        // put the string into the priority queue
        priority_queue<pair<int, char>> pq;
        for (auto [c, cnt]: umap){
            pq.push({cnt, c});
        }
        pair<int, char> prev = {0, '#'};
        string result;
        while (!pq.empty()){
            auto [cnt, c] = pq.top();
            pq.pop();
            cnt--;
            result.push_back(c);
            // The previously used character can now return.
            if (prev.first > 0) 
                pq.push(prev);
            // hold the current character
            prev = {cnt, c};
        }

        if (s.size() != result.size()) return "";
        return result;
    }
};