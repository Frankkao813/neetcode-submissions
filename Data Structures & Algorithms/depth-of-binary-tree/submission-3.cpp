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
    int depthHelper(TreeNode* root){
        // DFS (bottom-up version)
        if (!root) return 0;
        int left = depthHelper(root -> left);
        int right = depthHelper(root -> right);
        return 1 + max(left, right);
    }   
public:
    int maxDepth(TreeNode* root) {
        return depthHelper(root);
    }
};
