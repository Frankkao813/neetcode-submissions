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
        // M2: slow and fast pointer + reverse the second list + merge alternatively


        // slow and faster pointer to find the middle node
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;   
        }

        // cut into two section + reverse the second half
        ListNode* second = slow -> next;
        slow -> next = nullptr;

        ListNode* prev = nullptr;
        while (second){
            ListNode* secondNext = second -> next;
            second -> next = prev;
            prev = second;
            second = secondNext;
        }

        // merge the two alternatively
        ListNode* first = head;
        second = prev;

        while (second){
            ListNode* firstNext = first -> next;
            ListNode* secondNext = second -> next;
            first -> next = second;
            second -> next = firstNext;
            first = firstNext;
            second = secondNext;
        }

    }
};
