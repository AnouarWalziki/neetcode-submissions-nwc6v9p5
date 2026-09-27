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
        
        while(l1 || l2 || carry){
            int sum1 = l1 ? l1->val : 0;
            int sum2 = l2 ? l2->val : 0;

            // new digit
            int sum = sum1 + sum2 + carry;
            carry = sum / 10;
            int keep = sum % 10;
            current->next = new ListNode(keep);

            // update pointers
            current = current->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummy.next;
    }
};
