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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while(l1 || l2){
            int sum1 = 0;
            int sum2 = 0;
            if(l1){
                sum1 = l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum2 = l2->val;
                l2 = l2->next;
            }

            int sum = sum1 + sum2 + carry;
            carry = sum / 10;
            int keep = sum % 10;
            current->next = new ListNode(keep);
            current = current->next;
        }

        if(carry){
            current->next = new ListNode(carry);
            current->next->next = nullptr;
        }

        return dummy.next;
    }
};
