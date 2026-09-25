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
        deque<ListNode*> nodes;
        ListNode* current = head;
        while(current){
            nodes.push_back(current);
            current = current->next;
        }

        while(nodes.size() != 1){
            ListNode* first = nodes.front();
            ListNode* last = nodes.back();

            first->next = last;
            nodes.pop_front();

            if(nodes.size() != 1){
                last->next = nodes.front();
                nodes.pop_back();
            }
        }

        nodes.front()->next = nullptr;
    }
};
