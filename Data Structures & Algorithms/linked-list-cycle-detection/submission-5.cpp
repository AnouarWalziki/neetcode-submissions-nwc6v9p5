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

// Bad intuition..infinite loop :C !!!!!!!!!!!!!

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head)
            return false;

        ListNode* current = head;

        while(current){
            if(!current->next)
                return false;

            current = current->next;
        }
        return true;
    }
};
