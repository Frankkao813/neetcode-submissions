class Solution {
   private:
    int calculateSubstring(string s, int start, int end, int k){
        // create a hashmap
        int substring_len = end - start + 1;
        unordered_map<char, int> umap;
        int maxFreq = -1; 
        for (int i = start; i <= end; i++){
            umap[s[i]]++;
            maxFreq = max(maxFreq, umap[s[i]]);
        }

        // Idea: If the replacement is smaller than the maximum allowed number, we can replace it
        int replacement = substring_len - maxFreq;
        if (replacement <= k){
            return substring_len;
        }

       return -1; 
    }
   public:
    int characterReplacement(string s, int k) {
        // Method 1: Brute Force
        int result = -1;
        for (int i = 0; i < s.size() - 1; i++){
            for (int j = i + 1; j < s.size(); j++){
                int length = calculateSubstring(s, i, j, k);
                if (length != -1){
                    result = max(result, length);
                }
            }
        }

        return result;
    }
};
