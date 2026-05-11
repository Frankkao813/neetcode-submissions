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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr1 = nullptr;
        ListNode* ptr2 = head;
        while (ptr2 != nullptr){
            ListNode* temp = ptr2 -> next;
            ptr2 -> next = ptr1;
            ptr1 = ptr2;
            ptr2 = temp;
        }

        return ptr1;
    }
};
