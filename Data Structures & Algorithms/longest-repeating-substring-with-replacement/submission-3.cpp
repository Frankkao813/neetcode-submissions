class Solution {

   public:
    int characterReplacement(string s, int k) {
        // Method 2: Sliding Window
        int start = 0;
        int maxLength = -1;
        unordered_map<char, int> umap;
        int freq_cnt = 0;
        for (int end = 0; end < s.size(); end++){
            umap[s[end]]++;
            freq_cnt = max(freq_cnt, umap[s[end]]);
            // invalid window condition
            while ((end - start + 1) - freq_cnt > k){
                umap[s[start]]--;
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;

    }
};
