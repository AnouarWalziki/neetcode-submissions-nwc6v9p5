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

int getListSize(ListNode* head){
    ListNode* current = head;
    int count = 0;
    while(current){
        count++;
        current = current->next;
    }
    return count;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        ListNode* prev = new ListNode();
        int size = getListSize(head);
        int toRemove = size - n + 1;
        int count = 0;
        while(current){
            count++;
            if(count != toRemove){
                prev = current;
                current = current->next;
            } else {
                prev->next = current->next;
                break;
            }
        }

        if(toRemove == 1){
            return prev->next;
        }
        return head;
    }
};
