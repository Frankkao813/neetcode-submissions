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
    bool hasCycle(ListNode* head) {
        // method: set operation
        // add the address of the node into the set
        // If the ptr goes to the end without adding duplicate element, there is no cycle
        unordered_set<ListNode*> uset;
        ListNode* ptr = head;
        while (ptr != nullptr){
            auto result = uset.insert(ptr);
            if (!result.second){
                return true;
            }
            ptr = ptr -> next;   
        }

        return false;


    }
};
