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

class Solution {
// Method: Binary Tree Level Order Traversal
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()){
            int qSize = q.size();
            for (int i = 0; i < qSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                // process
                if (i == qSize - 1){
                    result.push_back(curr -> val);
                }
                if (curr -> left) q.push(curr -> left);
                if (curr -> right) q.push(curr -> right);
            }
        }
        return result;
        
    }
};
