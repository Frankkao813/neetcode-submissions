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
    vector<int> nodes;
    void postorder(TreeNode* curr){
        if (curr == nullptr) return;
        postorder(curr -> left);
        postorder(curr -> right);
        nodes.push_back(curr -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);

        return nodes;
    }
};