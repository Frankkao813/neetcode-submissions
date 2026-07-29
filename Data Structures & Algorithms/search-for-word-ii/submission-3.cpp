

class Solution {
// I will first code out the structure for the Word Search I
private:

    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};;
    bool dfs(vector<vector<char>>& board, int row, int col, int index, string& word){
        if (index == word.size()) return true;

        int m = board.size();
        int n = board[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n) return false;
        if (word[index] != board[row][col]) return false;

        char ch = board[row][col];
        board[row][col] = '-';
        bool found = false;

        for (auto dir: directions){
            if (dfs(board, row + dir.first, col + dir.second, index + 1, word)){
                found = true;
                break;
            }
        }

        board[row][col] = ch;
        return found;


    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> result;

        for (auto word: words){
            bool foundWord = false;
            for (int i = 0; i < m && !foundWord; i++){
                for (int j = 0; j < n; j++){
                    if (dfs(board, i, j, 0, word)){
                        result.push_back(word);
                        foundWord = true;
                        break;
                    }
                }
            }
        }

        return result;

    }
};
