class Solution {
public:
    // M2: precomputed table
    int trap(vector<int>& height) {
        // rain[i] = min(L, R) - h[i];
        // We include the index we want to obtain answer, key property: min(maxLeft, maxRight) >= height[i]
        // Therefore, the result of each index will never be negative
        int m = height.size();
        int result = 0;
        vector<int> maxLeft(m, 0);
        vector<int> maxRight(m, 0);
        int currentMax = 0;
        // precompte the highest wall from 0 ... n-1
        for (int i = 0; i < m; i++){
            currentMax = max(currentMax, height[i]);
            maxLeft[i] = currentMax;
        }
        currentMax = 0;
        // precompte the highest wall from n-1 ... 1
        for (int i = m - 1; i >= 0; i--){
            currentMax = max(currentMax, height[i]);
            maxRight[i] = currentMax;
        }


        for (int i = 0; i < m; i++){
            // calculate the left and right height with the precomputed table
            result += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return result;
        
    }
};
