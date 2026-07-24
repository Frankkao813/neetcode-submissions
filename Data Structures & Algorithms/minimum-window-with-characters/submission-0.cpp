class Solution {
private:
    bool contain(string sub, string t){
        // use an unordered_map to calculate the frequency
        // each vocabulary will not appear only once. Instead, it will 
        unordered_map<char, int> umap;
        for (char c: sub){
            umap[c]++;
        }
        for (char c: t){
            umap[c]--; // The char originally not existed will be -1
            if (umap[c] < 0) return false;
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        // brute force: initailize a two pointer, when we get a interval
        // see that if the interval contains the necessary t

        // How to make it vert long?
        string result;
        for (int start = 0; start < s.size(); start++){
            for (int end = start; end < s.size(); end++){
                string curr = s.substr(start, end - start + 1);
                if (contain(curr, t)){

                    if (result.empty() || curr.size() < result.size()){
                        result = curr;
                    }
                }
            }
        }

        return result;

    }
};
