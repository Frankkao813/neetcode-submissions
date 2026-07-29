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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* added = dummy;
        int val = -1;
        while (l1_curr != nullptr || l2_curr != nullptr){
            if (l1_curr != nullptr && l2_curr != nullptr){
                val = l1_curr -> val + l2_curr -> val + carry;
                l1_curr = l1_curr -> next;
                l2_curr = l2_curr -> next;
            }
            else if (l1_curr != nullptr){
                val = l1_curr -> val + carry;
                l1_curr = l1_curr -> next;
            }
            else if (l2_curr != nullptr){
                val = l2_curr -> val + carry;
                l2_curr = l2_curr -> next;
            }

            carry = val / 10;
            val = val % 10;
            added -> next = new ListNode(val);
            added = added ->  next;
        }
        // result
        if (carry > 0){
            added -> next = new ListNode(carry);
            added = added -> next;
        }
        return dummy -> next;
    }
};
