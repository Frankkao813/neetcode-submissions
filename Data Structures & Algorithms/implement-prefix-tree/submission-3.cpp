struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode():children(26, nullptr), isEnd(false){

    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char w: word){
            int ind = w - 'a';
            if (curr -> children[ind] == nullptr){
                curr -> children[ind] = new TrieNode();
            }
            curr = curr -> children[ind];
        }
        curr -> isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char w: word){
            int ind = w - 'a';
            if (curr -> children[ind] == nullptr){
                return false;
            }
            curr = curr -> children[ind];
        }
        return curr -> isEnd? true: false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char w: prefix){
            int ind = w - 'a';
            if (curr -> children[ind] == nullptr){
                return false;
            }
            curr = curr -> children[ind];
        }

        return true;
    }
};
