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
    bool validBSTHelper(TreeNode* root, long lower, long upper){
        // base case: empty node is a valid BST
        if (!root) return true;
        // check the BST on the local level
        if (root -> val <= lower || root -> val >= upper){
            return false;
        }

        // check the child
        return validBSTHelper(root -> left, lower, root -> val) &&
                validBSTHelper(root -> right, root -> val, upper);
        
    }
public:
    bool isValidBST(TreeNode* root) {
        bool result = validBSTHelper(root, LONG_MIN, LONG_MAX);
        return result;
    }
};
