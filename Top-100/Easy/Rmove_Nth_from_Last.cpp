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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode *curr = head, *nAhead = head;
        int k = n;
        while(k && nAhead) {
            nAhead = nAhead->next;
            k--;
        }
        ListNode *prev;
        while(nAhead && curr) {
            prev = curr;
            curr = curr->next;
            nAhead = nAhead->next;
        }
        if (curr == head)
            head = head->next;
        else
            prev->next = curr->next;

        return head;
    }
};
