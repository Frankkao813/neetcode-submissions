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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* fastptr = dummy;
        ListNode* slowptr = dummy;
        int movement = 0;
        for (int i = 0; i <= n; i++){
            fastptr = fastptr -> next;
            movement++;
            if (fastptr == nullptr) break;
        }

        if (movement != n + 1) return nullptr;

        while (fastptr != nullptr){
            fastptr = fastptr -> next;
            slowptr = slowptr -> next;
        }

        // node to delete
        ListNode* toDelete = slowptr -> next;
        slowptr -> next = slowptr -> next -> next;
        delete toDelete;

        return dummy -> next;

    }
};
