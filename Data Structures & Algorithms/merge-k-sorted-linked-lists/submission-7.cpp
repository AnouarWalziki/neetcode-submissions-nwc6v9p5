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

        auto cmp = [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                minHeap.push({i, lists[i]->val});
        }

        while(!minHeap.empty()){
            auto [minId, minVal] = minHeap.top();
            minHeap.pop();

            curr->next = lists[minId];
            curr = curr->next;
            lists[minId] = lists[minId]->next;
            if(lists[minId])
                minHeap.push({minId, lists[minId]->val});
        }

        return res.next;
    }
};
