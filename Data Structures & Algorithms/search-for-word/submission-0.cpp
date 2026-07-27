class Solution {
private:
    vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfsHelper(vector<vector<char>>& board, int row, int col, int index, string& word){
        // boundary check
        int m = board.size();
        int n = board[0].size();
        if (index == word.size()){
            return true;
        }
        if (row < 0 || row >= m || col < 0 || col >= n){
            return false;
        }

        if (word[index] != board[row][col]) return false;


        // mark visited
        char temp = board[row][col];
        board[row][col] = '#';

        bool found = false;
        for (auto dir : dirs){
            if (dfsHelper(board, row + dir.first, col + dir.second, index + 1, word)){
                found = true;
                break; // short-circuit once found
            }
        }

        // unmark
        board[row][col] = temp;

        return found;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfsHelper(board, i, j, 0, word) == true){
                    return true;
                }
            }
        }

        return false;
    }
};
