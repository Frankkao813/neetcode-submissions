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
    unordered_map<int, int> inorderIndex; // num: inorder index 
    int preorderIndex = 0;
    TreeNode* build(
        vector<int>& preorder,
        int inorderLeft,
        int inorderRight
    ){
        // no nodes exist in this inorder range
        if (inorderLeft > inorderRight){
            return nullptr;
        }

        int rootValue = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(rootValue);
        int rootPosition = inorderIndex[rootValue];
        root -> left = build(preorder, inorderLeft, rootPosition - 1);
        root -> right = build(preorder, rootPosition + 1, inorderRight);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // since the first element in the preorder is the root
        // At the root element of inorder, the left is the left subtree, and the right is the right subtree
        for (int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
