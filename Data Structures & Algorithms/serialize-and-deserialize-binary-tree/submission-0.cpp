/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // binary tree bfs
        string result;
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int currSize = q.size();
            for (int i = 0; i < currSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                if (curr == nullptr){
                    result += "#,";
                    continue;
                }

                result += to_string(curr -> val);
                result += ",";

                q.push(curr -> left);
                q.push(curr -> right);
                
            }
            
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        // string splitting
        string token;
        vector<string> values;
        stringstream ss(data);

        while (getline(ss, token, ',')){
            values.push_back(token);
        }

        // reconstruct the tree
        //TreeNode() expects the number input
        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        int index = 1;
        while (!q.empty() && index < values.size()){
            TreeNode* node = q.front();
            q.pop();

            // construct left children from array
            if (values[index] != "#") {
                node->left = new TreeNode(stoi(values[index]));
                q.push(node->left);
            }

            index++;
            // construct right children
            if (index < values.size() && values[index] != "#"){
                node -> right = new TreeNode(stoi(values[index]));
                q.push(node -> right);

            }
            index++;
            
        }

        return root;

    }
};
