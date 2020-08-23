/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// solution 1 - put the lists together
// let pointerA inetrate over A+B
// and pointerB iterate over B+A,
// since these lists have even length,
// when pointerA meets pointerB we have our intersection.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode *pA = headA;
        ListNode *pB = headB;

        while(pA != NULL || pB != NULL) {
            if(pA == pB)
                return pA;
            else {
                if(pA == NULL && pB != NULL) {
                    pA = headB;
                    pB = pB->next;
                }
                else if(pB == NULL && pA != NULL) {
                    pA = pA->next;
                    pB = headA;
                }
                else if(pA != NULL && pB != NULL) {
                    pA = pA->next;
                    pB = pB->next;
                }
            }
        }
        return NULL;
    }
};

//soltuion 2 - using lenght difference
// First get the lenght difference.
// Then advance the pointer of the longer list by the difference.
// Now do the two pinter approach.
// When these 2 pinters meet that's our solution.
