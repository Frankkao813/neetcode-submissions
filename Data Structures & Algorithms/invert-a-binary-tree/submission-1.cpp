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
    // method: BFS
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root){
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            // swap the pointer first
            swap(curr -> left, curr -> right);
            // deal with the left and right child
            if (curr -> left){
                q.push(curr -> left);
            }
            
            if (curr -> right){
                q.push(curr -> right);
            }
        }


        return root;
    }
};
