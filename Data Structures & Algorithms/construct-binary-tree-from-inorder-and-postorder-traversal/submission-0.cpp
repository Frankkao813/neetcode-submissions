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
    unordered_map<int, int> inorderIndex;
    int postorderIndex;
    // postorder provides the number required for building the tree
    TreeNode* build(vector<int>& postorder, int left, int right){
        if (right < left) return nullptr; // no valid subtree at this range
        int rootVal = postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = inorderIndex[rootVal];
        root -> right  = build(postorder, rootIndex + 1, right);
        root -> left = build(postorder, left, rootIndex - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // first the correspondence between inorder element and the index
        postorderIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i; 
        }
        return build(postorder, 0, inorder.size() - 1);
    }
};