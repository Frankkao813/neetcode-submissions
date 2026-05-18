
// Note: Remember to add this struct
struct TreeNode{
    bool isEnd;
    TreeNode* children[26];

    TreeNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};


class PrefixTree {
    // method: dictionary tree
    TreeNode* root;


public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TreeNode* curr = root;
        
        for (int i = 0; i < n; i++){
            int ind = word[i] - 'a';
            if (not curr -> children[ind]){
                TreeNode* node = new TreeNode();
                curr -> children[ind] = node;
            }

            curr = curr -> children[ind];
        }
        // mark the end of this word
        curr -> isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TreeNode* curr = root;
        for (int i = 0; i < n; i++){
            int ind = word[i] - 'a';
            if (not curr -> children[ind]){
                return false;
            }
            curr = curr -> children[ind];
        }
        
        return curr -> isEnd;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TreeNode* curr = root;
        for (int i = 0; i < n; i++){
            int ind = prefix[i] - 'a';
            if (not curr -> children[ind]){
                return false;
            }
            curr = curr -> children[ind];
        }
        
        // We don't need to check whether it is end of word or not
        return true;
    }
};
