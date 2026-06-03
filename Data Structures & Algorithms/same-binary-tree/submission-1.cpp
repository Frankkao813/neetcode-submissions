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
    // Two queues, each doing BFS at the same time
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false; //  either of the tree is empty
        queue<TreeNode*> a;
        queue<TreeNode*> b;
        a.push(p);
        b.push(q);

        while (!a.empty() && !b.empty()){
            TreeNode* a_curr = a.front(); a.pop();
            TreeNode* b_curr = b.front(); b.pop();
            // if a_curr and b_curr both empty
            if (!a_curr && !b_curr) continue;
            // one of them doesn't exist
            if (!a_curr || !b_curr) return false;
            // two values doesn't match
            if (a_curr -> val != b_curr -> val) return false;

            // for this problem, the structure matters
            a.push(a_curr -> left);
            a.push(a_curr -> right);
            b.push(b_curr -> left);
            b.push(b_curr -> right);

        }

        return true;
    }
};
