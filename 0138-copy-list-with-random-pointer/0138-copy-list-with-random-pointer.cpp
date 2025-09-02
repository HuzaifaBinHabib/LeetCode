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
        if (!head) return nullptr;  

        unordered_map<Node*, Node*> m;
        Node* newhead = new Node(head->val);
        Node* newtemp = newhead;
        Node* oldtemp = head->next;
        m[head] = newhead;
        while (oldtemp != nullptr) {
            Node* copytemp = new Node(oldtemp->val);
            m[oldtemp] = copytemp;
            newtemp->next = copytemp;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        oldtemp = head;
        newtemp = newhead;
        while (oldtemp != nullptr) {
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return newhead;
    }
};