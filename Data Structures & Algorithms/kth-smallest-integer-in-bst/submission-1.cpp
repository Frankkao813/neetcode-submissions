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
    vector<int> nums;
    void inorderHelper(TreeNode* curr){
        if (curr == nullptr) return;
        inorderHelper(curr -> left);
        nums.push_back(curr -> val);
        inorderHelper(curr -> right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // first do inorder traversal
        inorderHelper(root);
        return nums[k - 1];
        
    }
};
