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
        vector<int> vals;

        while(list1){
            vals.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2){
            vals.push_back(list2->val);
            list2 = list2->next;
        }
        std::sort(vals.begin(), vals.end());

        if(vals.empty()){
            return nullptr;
        }

        ListNode* head = new ListNode(vals[0]);
        ListNode* current = head;
        for(int i = 1; i < vals.size(); i++){
            current->next = new ListNode(vals[i]);
            current = current->next;
        }
        return head;
    }
};
