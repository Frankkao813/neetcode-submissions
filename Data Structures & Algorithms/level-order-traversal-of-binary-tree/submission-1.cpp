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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        while (!q.empty()){
            int qSize = q.size();
            vector<int> currLevel;
            for (int i = 0; i <qSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr -> val);
                if (curr -> left) q.push(curr -> left);
                if (curr -> right) q.push(curr -> right);
            }
            result.push_back(currLevel);
        }

        return result;
    }
};
