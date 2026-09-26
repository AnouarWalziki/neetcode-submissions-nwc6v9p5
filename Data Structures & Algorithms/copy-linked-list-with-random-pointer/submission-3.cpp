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
        unordered_map<Node*, int> positions;
        unordered_map<int, Node*> pointers;
        int pos = 0;
        while(curr1){
            curr2->val = curr1->val;
            positions[curr1] = pos;
            pointers[pos] = curr2;
                       
            if(curr1->next){
                curr2->next = new Node(0);
            } else{
                curr2->next = nullptr;
            }

            pos++;
            curr2 = curr2->next;
            curr1 = curr1->next;
        }

        // fill randoms
        curr1 = head;
        curr2 = copy;
        while(curr1){
            Node* rnd = curr1->random;
            if(rnd){
                curr2->random = pointers[positions[rnd]];
            } else{
                 curr2->random = nullptr;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return copy;
    }
};
