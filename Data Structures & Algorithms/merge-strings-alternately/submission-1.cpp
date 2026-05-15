class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n1 = word1.size();
        int n2 = word2.size();
        string result;
        while (ptr1 < n1 and ptr2 < n2){
            result.push_back(word1[ptr1]);
            ptr1++;
            result.push_back(word2[ptr2]);
            ptr2++;
        }
        // Add the remaining word
        while (ptr1 < n1){
            result.push_back(word1[ptr1]);
            ptr1++;
        }

        while (ptr2 < n2){
            result.push_back(word2[ptr2]);
            ptr2++;
        }
        return result;
    }
};