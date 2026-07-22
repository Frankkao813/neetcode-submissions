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
    TreeNode* lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* leftResult = lcaHelper(root -> left, p, q);
        TreeNode* rightResult = lcaHelper(root -> right, p, q);
        // scenario: p and q on both sides
        if (leftResult && rightResult) return root;
        // scenario: p and q are both on one side
        if (leftResult) {
            return leftResult;
        }

        if (rightResult) {
            return rightResult;
        }

        return nullptr;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcaHelper(root, p, q);
    }
};
