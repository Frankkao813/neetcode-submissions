class Solution {
public:
    string convertToTitle(int columnNumber) {
        // It is a base 26 number
        int num = columnNumber;
        string colTitle;
        while (num > 0){
            // adjust for 1-based index
            // In this case, A -> 0 and Z -> 25
            num--;
            int remainder = num % 26;
            colTitle.push_back(remainder + 'A');
            num /= 26;
        }
        std::reverse(colTitle.begin(), colTitle.end());
        return colTitle;
    }
};