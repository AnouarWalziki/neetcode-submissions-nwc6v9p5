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
    bool hasCycle(ListNode* head) {
        if(!head)
            return false;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        int freq = 2;

        while(p1 && p2){
            if(freq != 0){
                p2 = p2->next;
                freq--;
            } else{
                p1= p1 -> next;
                freq = 2;
            }

            if(p1 == p2){
                return true;
            }
        }
        return false;
    }
};
