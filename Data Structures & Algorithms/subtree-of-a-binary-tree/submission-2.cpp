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
    bool sameTree(TreeNode* a, TreeNode* b){
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr) return false;
        if (a -> val != b -> val) return false;
        return sameTree(a -> left, b -> left) && sameTree(a -> right, b -> right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // !subRoot && root -> true 
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            // check if this node corresponds to the root start
            if (curr -> val == subRoot -> val && sameTree(curr, subRoot)){
                return true;
            }
            if (curr -> left) q.push(curr -> left);
            if (curr -> right) q.push(curr -> right);
        }

        return false;
    }
};
