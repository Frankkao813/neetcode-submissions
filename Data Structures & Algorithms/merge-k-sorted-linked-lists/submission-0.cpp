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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // approach: push everything into minHeap, and then we connect the linked list
        // step1: push everything into minHeap
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        for (int i = 0; i < lists.size(); i++){
            ListNode* curr = lists[i];
            while (curr != nullptr){
                minHeap.push(curr -> val);
                curr = curr -> next;
            }
        }


        // step2: reconstruct the array
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while (!minHeap.empty()){
            int curr = minHeap.top();
            minHeap.pop();
            ptr -> next = new ListNode(curr);
            ptr = ptr -> next;
        }

        return dummy -> next;

    }
};
