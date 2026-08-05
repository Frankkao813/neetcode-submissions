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

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr){
            return nullptr;
        }

        // start to find the node
        if (key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else if (key > root -> val){
            root -> right = deleteNode(root -> right, key);
        }
        else{
            // No left child: return right child, which may also be nullptr
            if (!root -> left) return root -> right;
            // No right child: return left child
            if (!root -> right) return root -> left;
            // both children exist, find the smallest value
            TreeNode* successor = root -> right;
            while (successor -> left != nullptr){
                successor = successor -> left;
            }
            // copy the found node to the root
            root -> val = successor -> val;
            // delete the node
            root->right = deleteNode(root -> right, root -> val);

        }

        return root;
    }
};