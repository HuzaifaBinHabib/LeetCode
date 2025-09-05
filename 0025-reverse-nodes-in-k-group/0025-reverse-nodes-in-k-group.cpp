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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (count < k) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
            count++;
        }
        ListNode* prevnode = reverseKGroup(temp, k);

        count = 0;
        temp = head;
        while (count < k) {
            ListNode* newnext = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = newnext;
            count++;
        }
        return prevnode;
    }
};