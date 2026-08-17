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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;

        auto* next = head->next;
        auto* before = head;
        head->next = nullptr;
        head = next;

        while(head->next){
            next = head->next;
            head->next = before;
            before = head;
            head = next;
        }
        
        head->next = before;
        return head;
    }
};
