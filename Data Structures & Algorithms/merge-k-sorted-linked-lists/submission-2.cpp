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
        for(ListNode* lst : lists){
            while(lst){
                values.push_back(lst->val);
                lst = lst->next;
            }
        }

        sort(values.begin(), values.end());

        ListNode dummy;
        ListNode* current = &dummy;
        for(int i = 0; i < values.size(); i++){
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return dummy.next;
    }
};
