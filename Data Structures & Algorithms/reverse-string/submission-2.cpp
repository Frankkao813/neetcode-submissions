class Solution {
public:
    void reverseString(vector<char>& s) {
        // method: Two Pointer
        // Starting at both sides
        int startPtr = 0;
        int endPtr = s.size() - 1;
        while (startPtr <= endPtr){
            // swap the element that the two pointers point to
            std::swap(s[startPtr], s[endPtr]);
            // both pointer moving inward for one step in each iteration
            startPtr++;
            endPtr--;
        }   

    }
};