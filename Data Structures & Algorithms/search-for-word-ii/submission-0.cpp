struct TrieNode{
    TrieNode* children[26];
    bool isEnd;

    string word;

    TrieNode(){
        isEnd = false;
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

};

class Solution {
// I will first code out the structure for the Word Search I
private:
    
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();

        for (auto word: words){
            TrieNode* curr = root;
            for (auto ch: word){
                if (curr -> children[ch - 'a'] == nullptr){
                    curr -> children[ch - 'a'] = new TrieNode();
                }
                curr = curr -> children[ch - 'a'];
            }
            curr -> isEnd = true;
            curr -> word = word;
        }

        return root;
    }
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};;
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node, vector<string>& result){
        int m = board.size();
        int n = board[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n) return;
        if (board[row][col] == '-') return;

        // save the current one
        char ch = board[row][col];
        int childIndex = ch - 'a';
        

        // move forward in the trie
        TrieNode* nextNode = node -> children[childIndex];
        if (nextNode == nullptr) return;

        if (!nextNode->word.empty()) {
            result.push_back(nextNode->word);
            nextNode->word = "";
        }

        board[row][col] = '-';
        for (auto dir: directions){
            dfs(
                board,
                row + dir.first,
                col + dir.second,
                nextNode,
                result
            );
        }

        // backtrack
        board[row][col] = ch;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        TrieNode* root = buildTrie(words);
        vector<string> result;

        for (int i = 0 ; i < m; i++){
            for (int j = 0; j < n; j++){
                dfs(board, i, j, root, result);
            }
        }

        return result;

    }
};
