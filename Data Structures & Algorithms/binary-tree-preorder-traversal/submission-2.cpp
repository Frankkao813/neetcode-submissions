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
private:
    vector<int> seq;
    void preorderHelper(TreeNode* root){
        if (!root) return;
        seq.push_back(root -> val);
        preorderHelper(root -> left);
        preorderHelper(root -> right);

    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorderHelper(root);
        return seq;
    }
};