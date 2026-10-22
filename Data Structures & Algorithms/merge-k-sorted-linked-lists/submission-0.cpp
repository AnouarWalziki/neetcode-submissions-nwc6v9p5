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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;
        while(true){
            bool inserted = false;
            for(ListNode*& node : lists){
                if(node){
                    values.push_back(node->val);
                    inserted = true;
                    node = node->next;
                }
            }
            if(!inserted)
                break;
        }

        if(values.empty())
            return nullptr;

        sort(values.begin(), values.end());
        ListNode* head = new ListNode();
        ListNode* current = head;
        for(int i = 0; i < values.size(); i++){
            current->val = values[i];
            if(i != values.size() - 1){
                current->next = new ListNode();
            }
            current = current->next;
        }
        return head;
    }
};
