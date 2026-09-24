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
        if(!head || !(head->next)){
            return false;
        }

        set<ListNode*> uniques;
        uniques.insert(head);
        ListNode* current = head;

        while(current){
            // Reached the tail
            if(!current->next){
                return false;
            }

            size_t sizeBefore = uniques.size();
            uniques.insert(current->next);
            
            if(uniques.size() == sizeBefore){
                return true;
            }

            current = current->next;
        }
        return false;
    }
};
