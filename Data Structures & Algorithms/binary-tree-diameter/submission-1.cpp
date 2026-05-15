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
    int maxDiameter = -1;
    int heightHelper(TreeNode* root){
        if (root == nullptr) return 0;
        int left = heightHelper(root -> left);
        int right = heightHelper(root -> right);
        maxDiameter = max(maxDiameter, left + right); // update the global diameter
        return max(left, right) + 1; // return height for the parent to use

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        heightHelper(root);
        return maxDiameter;
    }
};
