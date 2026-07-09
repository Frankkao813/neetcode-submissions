/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        // M1: brute force
        vector<int> nums;
        ListNode* curr = head;
        while (curr){
            nums.push_back(curr -> val);
            curr = curr -> next;
        }

        if (nums.size()== 1){
            return;
        }

        // overwrite the values of the original nodes in reordered sequence
        curr = head;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            if (left == right){
                curr -> val = nums[left];
                left++;
                break;
            }
            int left_element = nums[left];
            int right_element = nums[right];
            curr -> val = left_element;
            curr = curr -> next;
            curr -> val = right_element;
            curr  = curr -> next;
            left++;
            right--;
        }



    }
};
