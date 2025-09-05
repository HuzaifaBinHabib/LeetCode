/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* newnext = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                curr = curr->next;

                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                if (newnext != nullptr) {
                   curr->next = newnext;
                    newnext->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};