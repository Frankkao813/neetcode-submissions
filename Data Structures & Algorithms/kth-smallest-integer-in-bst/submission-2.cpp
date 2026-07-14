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
    int answer;
    int count = 0;
    void inorderHelper(TreeNode* curr, int k){
        if (curr == nullptr) return;
        inorderHelper(curr -> left, k);
        nums.push_back(curr -> val);
        count++;
        // update: stop when the number of elements in the vector is k
        if (count == k) {
            answer = curr->val;
            return;
        }
        inorderHelper(curr -> right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // first do inorder traversal
        inorderHelper(root, k);
        return answer;
        
    }
};
