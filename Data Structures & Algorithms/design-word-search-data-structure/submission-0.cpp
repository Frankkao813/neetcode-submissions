struct TreeNode{
    bool isEnd;
    TreeNode* children[26];
    TreeNode(){
        isEnd = false;
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TreeNode* root;
    WordDictionary() {
        root = new TreeNode();   
    }
    
    void addWord(string word) {
        TreeNode* curr =root;
        for (char w: word){
            int ind = w - 'a';
            if (!curr -> children[ind]){ // the slot is empty
                TreeNode* node = new TreeNode();
                curr -> children[ind] = node;
            }
            curr = curr -> children[ind];
        }
        curr -> isEnd = true;
        return;
    }

    bool searchHelper(string word, int i, TreeNode* root){
        // The children doesn't contain this character
        if (root == nullptr) return false;
        
        if (i == word.size()){
            return root -> isEnd;
        }
        char c = word[i];
        // wild card character
        if (c == '.') {
            // Try every possible child
            for (int j = 0; j < 26; j++) {
                // Only try this path if the child exists
                if (root->children[j] != nullptr) {
                    // If any child path works, we return true
                    if (searchHelper(word, i + 1, root->children[j])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            // Normal character: only one path
            int ind = c - 'a';
            return searchHelper(word, i + 1, root->children[ind]);
        }

        
    }
    
    bool search(string word) {

        return searchHelper(word, 0, root);
        
    }
};
