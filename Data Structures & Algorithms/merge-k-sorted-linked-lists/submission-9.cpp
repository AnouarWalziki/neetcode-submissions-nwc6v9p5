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
        ListNode res;
        ListNode* curr = &res;

        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        for(ListNode* lst : lists){
            if(lst)
                minHeap.push(lst);
        }

        while(!minHeap.empty()){
            ListNode* node= minHeap.top();
            minHeap.pop();

            curr->next = node;
            curr = curr->next;
            if(node->next)
                minHeap.push(node->next);
        }

        return res.next;
    }
};
