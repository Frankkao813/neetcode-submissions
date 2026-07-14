class Solution {
private:
    bool checkRow(vector<vector<char>>& board, int m){
        int n = board[0].size();
        unordered_set<char> seen;
        for (int i = 0; i < n; i++){
            char value = board[m][i];
            if (value == '.') {
                continue;
            }

            
            if (seen.count(value)){
                return false;
            }
            seen.insert(value);
        }

        return true;
    }

    bool checkCol(vector<vector<char>>& board, int n){
        int m = board.size();
        unordered_set<char> seen;
        for (int i = 0; i < m; i++){
            char value = board[i][n];
            if (value == '.') {
                continue;
            }

            
            if (seen.count(value)){
                return false;
            }
            seen.insert(value);
        }
        return true;
    }
    bool check33(vector<vector<char>>& board, int rawRow, int rawCol){
        unordered_set<char> seen;
        int startRow = rawRow * 3;
        int startCol = rawCol * 3;
        for (int i = startRow; i < startRow + 3; i++){
            for (int j = startCol; j < startCol + 3; j++){
                char value = board[i][j];

                if (value== '.') {
                    continue;
                }

                if (seen.count(value)){
                    return false;
                }
                seen.insert(value);
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
