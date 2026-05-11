class Solution {
public:
    bool isValid(string s) {
        // method: stack
        stack<char> st;
        for (char sChar: s){
            // push
            if (sChar == '(' || sChar == '{' || sChar == '['){
                st.push(sChar);
            }
            // pop check
            else {
                if (st.empty()) {
                    return false;
                }
            
                if ((sChar == ')' and st.top() != '(') || 
                    (sChar == ']' and st.top() != '[') ||
                    (sChar == '}' and  st.top() != '{')){
                    return false;
                }

                st.pop();
            }

        }

        return st.empty();
    }
};
