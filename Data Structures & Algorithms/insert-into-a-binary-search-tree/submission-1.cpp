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
    TreeNode* dfsHelper(TreeNode* curr, int val){
        if (curr == nullptr){
            return new TreeNode(val);
        }

        // Insert val into the subtree whose root is curr, then return the root of that updated subtree.
        if (val < curr -> val){
            curr -> left = dfsHelper(curr -> left, val);
        }
        else {
            curr -> right = dfsHelper(curr -> right, val);
        }

        // return the current subtree root
        return curr;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // recursively find the node to insert
        return dfsHelper(root, val);
    }
};