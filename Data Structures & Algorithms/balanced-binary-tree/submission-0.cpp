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
    int heightDiff = 0;
    int balanceHelper(TreeNode* root){
        if (!root) return 0;
        int left = balanceHelper(root -> left);
        int right = balanceHelper(root -> right);
        heightDiff = max(heightDiff, abs(right - left));
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        balanceHelper(root);
        return heightDiff > 1? false: true;
    }
};
