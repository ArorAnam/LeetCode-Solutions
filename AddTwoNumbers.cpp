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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();

        ListNode *tmp = l3;
        int sum = 0;
        while(l1 != NULL || l2 != NULL) {
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            tmp->next = new ListNode(sum % 10);
            tmp = tmp->next;
            sum /= 10;
        }
        if(sum == 1)
            tmp->next = new ListNode(1);

        return l3->next;
    }
};
