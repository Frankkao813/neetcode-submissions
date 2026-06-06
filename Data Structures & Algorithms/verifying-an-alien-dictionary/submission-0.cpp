class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);
        for (int i = 0; i < order.size(); i++){
            rank[order[i] -'a'] = i;
        }

        // start to compare the words
        for (int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            // Compare characters until we find the first different one
            int j = 0;
            while (j < min(w1.size(), w2.size())){
                if (w1[j] != w2[j]){
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a']){
                        return false;
                    }
                    break;
                }
                j++;
            }
            
           // If w2 is a prefix of w1 but shorter, the order is invalid
            if (w2.size() == j && w1.size() > w2.size()){
                return false;
            }   
        }

        return true;
    }
};