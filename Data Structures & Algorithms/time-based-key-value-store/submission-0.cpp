class TimeMap {
    unordered_map<string, vector<std::pair<int, string>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // The value keep increasing
        umap[key].push_back({timestamp, value});
    }
    

    string get(string key, int timestamp) {
        string answer = "";
        if (umap.find(key) == umap.end()) return "";
        // make a reference for the specific key
        const vector<std::pair<int, string>>& curr = umap[key];

        // inclusive binary search pattern
        int left = 0;
        int right = curr.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (curr[mid].first <= timestamp){
                answer = curr[mid].second;
                left = mid + 1; // all the elements on the left are smaller, so we can omit those
            }
            else {
                right = mid - 1; // the current eleement is too big
            }
        }

        return answer;
    }
};
