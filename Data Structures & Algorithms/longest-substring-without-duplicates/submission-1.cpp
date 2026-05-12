class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int> umap;
        for (int right = 0; right < s.size(); right++){
            umap[s[right]]++;
            while (umap[s[right]] > 1){
                //std::cout << "encountered repetitive " << s[right] << std::endl; 
                umap[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
