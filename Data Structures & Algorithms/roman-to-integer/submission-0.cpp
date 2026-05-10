class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num = 0;
        for (int i = 0; i < s.size(); i++){
            num += umap[s[i]];
            if (i > 0){
                if  (s[i - 1] == 'I' && s[i] == 'V' || 
                s[i - 1] == 'I' && s[i] == 'X' ){
                    num -= 2;
                }
                if (s[i - 1] == 'X' && s[i] == 'L' || 
                s[i - 1] == 'X' && s[i] == 'C' ){
                    num -= 20;
                }

                if (s[i - 1] == 'C' && s[i] == 'D' || 
                s[i - 1] == 'C' && s[i] == 'M' ){
                    num -= 200;
                }

            }

        }
        return num;
    }
};