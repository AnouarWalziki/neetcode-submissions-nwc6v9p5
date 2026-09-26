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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = nullptr;
        ListNode* dummy = nullptr;
        while(list2){
            auto tmp = list2->next;
            list2->next = dummy;
            dummy = list2;
            if(!tmp){
                break;
            }
            list2 = tmp;
        }

        // reorder
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while(p1 || p2){
            ListNode* old;
            if(p1){
                old = p1->next;
                p1->next = p2;
                p1 = old;
            }
            if(p2){
                old = p2->next;
                if(p1){
                    p2->next = p1;
                }
                p2 = old;
            }
        } 
     }
};
