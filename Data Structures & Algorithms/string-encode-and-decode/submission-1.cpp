class Solution {
public:
    // Idea: length + delimeter + string
    // so that the other side can know the boundary of strings
    string encode(vector<string>& strs) {
        string encoded;
        for (string str: strs){
            int length = str.size();
            encoded += to_string(length) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        // 5#hello
        vector<string> result;

        int j = 0;
        while (j < s.size()){
            string numS; 
            while (s[j] != '#'){
                numS.push_back(s[j]);
                j++;
            }
            j++; // skip the pound sign
            string curr;
            int numI = stoi(numS);
            for (int i = 0; i < numI; i++){
                curr.push_back(s[j]);
                j++;
            }
            result.push_back(curr);
        }

        return result;
    }
};
