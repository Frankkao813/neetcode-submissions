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
private:
    struct compare{
        bool  operator()(ListNode* a, ListNode* b) const{
            // // Return true when a should have lower priority than b.
            return a -> val > b -> val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // approach:  better heap method -> We originally only push the first of each list
        // into the heap
        // step1: push everything into minHeap
        std::priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for (ListNode* head: lists){
            if (head) minHeap.push(head);
        }

    
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while (!minHeap.empty()){
            ListNode* minElement = minHeap.top();
            minHeap.pop();
            // push the element to the linked list
            tail -> next = minElement;
            tail = tail-> next;
            // check if there is other element in the list
            if (minElement -> next){
                minHeap.push(minElement -> next);
            }
        }

        return dummy.next;

    }
};
