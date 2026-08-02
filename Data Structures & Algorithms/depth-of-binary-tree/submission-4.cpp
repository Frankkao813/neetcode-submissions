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
    int dfsHelper(TreeNode* root){
        if (root == nullptr) return 0;
        int leftHeight = dfsHelper(root -> left);
        int rightHeight = dfsHelper(root -> right);
        // let each node contributes to the height
        return max(leftHeight, rightHeight) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfsHelper(root);
    }
};
