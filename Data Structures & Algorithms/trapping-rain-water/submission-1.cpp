class Solution {
public:
    int trap(vector<int>& height) {
        // rain[i] = min(L, R) - h[i];
        // We include the index we want to obtain answer, key property: min(maxLeft, maxRight) >= height[i]
        // Therefore, the result of each index will never be negative
        int m = height.size();
        int result = 0;
        for (int i = 0; i < m; i++){
            // calculate the left and right height
            int maxLeft =  -1;
            int maxRight = -1;
            for (int j = 0; j <= i; j++){
                maxLeft = max(maxLeft, height[j]); 
            }

            for (int j = i; j <m; j++){
                maxRight = max(maxRight, height[j]);
            }

            result += min(maxLeft, maxRight) - height[i];
        }

        return result;
        
    }
};
