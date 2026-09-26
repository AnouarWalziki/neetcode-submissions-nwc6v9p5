/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        // create copy without random part
        Node* copy = new Node(0);
        Node* curr1 = head;
        Node* curr2 = copy;
        while(curr1){
            curr2->val = curr1->val;
            
            if(curr1->next){
                curr2->next = new Node(0);
            } else{
                curr2->next = nullptr;
            }

            curr2 = curr2->next;
            curr1 = curr1->next;
        }

        // fill randoms
        curr1 = head;
        curr2 = copy;
        while(curr1){
            Node* rnd = curr1->random;
            if(rnd){
                Node* tmp1 = head;
                Node* tmp2 = copy;
                while(tmp1 != rnd){
                    tmp1 = tmp1->next;
                    tmp2 = tmp2->next;
                }
                curr2->random = tmp2;
            } else{
                 curr2->random = nullptr;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return copy;
    }
};
