class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // M1: open a new array, put the transpose array inside, and then copy back
        int n = matrix.size();
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                // derive one by one
                // (1, 0) -> (0, 1); (1, 1) -> (1, 1); (1, 2) -> (2, 1)
                mat[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = mat;
    }
};
