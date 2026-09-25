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
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode dummy;
        ListNode* current = &dummy;

        while(p1 || p2){
            if((p1 && !p2) || ((p1 && p2) && (p1->val <= p2->val))){
                current->next = p1;
                current = p1;
                p1 = p1->next;
            }
            else if ((p2 && !p1) || ((p1 && p2) && (p2->val < p1->val))){
                current->next = p2;
                current = p2;
                p2 = p2->next;
            }
        }
        return dummy.next;
    }
};
