class Solution {
private:
    bool isPalindrome(string s, int ptr1, int ptr2){
        while (ptr1 < ptr2){
            if (s[ptr1] == s[ptr2]){
                ptr1++;
                ptr2--;
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;
        while (ptr1 < ptr2){
            if (s[ptr1] == s[ptr2]){
                ptr1++;
                ptr2--;
            }
            else {
                // We either shrink left or right once
                return isPalindrome(s, ptr1 + 1, ptr2) || isPalindrome(s, ptr1, ptr2-1);

            }
        }
    }
};