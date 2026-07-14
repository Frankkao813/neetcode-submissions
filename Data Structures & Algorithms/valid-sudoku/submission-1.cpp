class Solution {
private:
    bool checkRow(vector<vector<char>>& board, int m){
        int n = board[0].size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++){

            if (board[m][i] == '.') {
                continue;
            }

            umap[board[m][i]] += 1;
            if (umap[board[m][i]] > 1){
                return false;
            }
        }

        return true;
    }

    bool checkCol(vector<vector<char>>& board, int n){
        int m = board.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < m; i++){

            if (board[i][n] == '.') {
                continue;
            }

            umap[board[i][n]] += 1;
            if (umap[board[i][n]] > 1){
                return false;
            }
        }
        return true;
    }
    bool check33(vector<vector<char>>& board, int rawRow, int rawCol){
        unordered_map<int, int> umap;
        for (int i = rawRow * 3; i < (rawRow + 1) * 3; i++){
            for (int j = rawCol * 3; j < (rawCol + 1) * 3; j++){

                if (board[i][j] == '.') {
                    continue;
                }

                umap[board[i][j]] += 1;
                if (umap[board[i][j]] > 1){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // each row must contain the digits 1-9 without duplicates
        for (int i = 0; i < m; i++){
            bool currRow = checkRow(board, i);
            if(currRow == false) return false;
        }
        // each column must contain the digits 1-9 without duplicates
        for (int j = 0; j < n; j++){
            bool currCol = checkCol(board, j);
            if (currCol == false) return false;
        }

        // Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
        for (int i = 0; i < 3; i++){
            for (int j = 0 ; j < 3; j++){
                bool currBlock = check33(board, i, j);
                if (currBlock == false) return false;
            }
        }

        return true;

    }
};
