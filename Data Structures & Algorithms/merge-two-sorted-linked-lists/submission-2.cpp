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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode dummy(0);
        ListNode* currNode = &dummy;
        while (ptr1 != nullptr and ptr2 != nullptr){
            if (ptr1 -> val <= ptr2 -> val){
                currNode -> next = ptr1;
                ptr1 = ptr1 -> next;
            }
            else {
                currNode -> next = ptr2;
                ptr2 = ptr2 -> next;
            }
            currNode = currNode -> next;
        }

        // attach the remaining listnode
        if (ptr1 != nullptr) {
            currNode->next = ptr1;
        } else {
            currNode->next = ptr2;
        }


        return dummy.next;
    }
};
