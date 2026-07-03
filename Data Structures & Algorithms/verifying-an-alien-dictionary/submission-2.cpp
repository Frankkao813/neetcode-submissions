class Solution {
    bool compareHelper(string s1, string s2, unordered_map<char, int>& umap){
        int s1_ind = 0;
        int s2_ind = 0;
        // see if the order is smaller
        while (s1_ind < s1.size() && s2_ind < s2.size()){
            // if the letter in the first word smaller than the letter in the second word
            if (umap[s1[s1_ind]] < umap[s2[s2_ind]]){
                return true;
            }
            // situation: bigger
            else if (umap[s1[s1_ind]] > umap[s2[s2_ind]]){
                return false;
            }
            // situation: the same character
            else {
                s1_ind++;
                s2_ind++;
            }
            
        }

        // handle the prefix case
        return s1.size() <= s2.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // create the dictionary of the ordering
        unordered_map<char, int> rank;
        for (int i = 0; i < order.size(); i++) {
            rank[order[i]] = i;
        }

        // start to compare the dictionary
        for (int i = 0; i < words.size() - 1; i++){
            bool result = compareHelper(words[i], words[i+1], rank);
            if (result == false){
                return false;
            }
        }

        return true;
        
    }
};