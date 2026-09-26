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

void splitList(ListNode* head, ListNode** list1, ListNode** list2){
    int size = 0;
    ListNode* current = head;
    // get list size
    while(current){
        size++;
        current = current->next;
    }

    *list1 = head;
    if(size == 1){
        *list2 = head;
        return;
    }

    int startIndex = size / 2;
    int index = 0;
    current = head;
    while(current){
        if(index < startIndex){
            index++;
        }

        if(index == startIndex){
            // seprate list1
            auto tmp = current->next;
            current->next = nullptr;
            // start of list2
            *list2 = tmp;
            break;
        } else {
            current = current->next;
        }
    }
}

void reverseList(ListNode** head){
    ListNode* current = *head;
    ListNode* dummy = nullptr;
    
    while(current){
        auto tmp = current->next;
        current->next = dummy;
        dummy = current;
        current = tmp;
    }
    *head = dummy;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        // cut list in half
        ListNode* list1;
        ListNode* list2;
        splitList(head, &list1, &list2);

        if(list1 == list2){
            return;
        }

        // reverse list2
        reverseList(&list2);

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

