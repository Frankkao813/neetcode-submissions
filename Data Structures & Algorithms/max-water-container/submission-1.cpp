class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ptr1 = 0;
        int ptr2 = heights.size() - 1;
        int result = 0;
        while (ptr1 < ptr2){
            int curr = min(heights[ptr2], heights[ptr1]) * (ptr2 - ptr1);
            result = max(curr, result);
            if (heights[ptr1] <= heights[ptr2]){
                ptr1++;
            }
            else{
                ptr2--;
            }
        }

        return result;
    }
};
