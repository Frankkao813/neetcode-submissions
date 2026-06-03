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
    // method: DFS
private:
    void invertTreeHelper(TreeNode* root){
        if (!root) return;
        // invert left tree
        invertTreeHelper(root -> left);
        // invert right tree
        invertTreeHelper(root -> right);
        //swap the pointers
        swap(root -> left, root -> right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }
};
