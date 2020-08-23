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
//Solution 1 - reverse first K and the recursively call
// the function to reverse next K
// This is causing TLE

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* curr = head;
            ListNode *next = NULL, *prev = NULL;
            int count = 0;

            while(curr != NULL && count < k) {
                next = curr->next;
                curr->next = curr;
                prev = curr;
                curr = next;
                count++;
            }

            // next is poining to the (k+1)th node
            if(next != NULL)
                head->next = reverseKGroup(next, k);

            //prev is the new head of the input list
            return prev;
    }
};

// Solution 2 -
// use a stack to store all the nodes
// Firstly push k elements in the stack,
// now pop elements one nby one from the stack
// and keep track of the previously poppped node,
// point the next pointer of the prev node to the top element of the stack
// Repeat this until NULL is reahed
// Note - NOT WORKING!!
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
        ListNode *curr = head, *prev = NULL;

        while(curr != NULL) {
            int cnt = 0;
            while(curr != NULL && cnt < k) {
                s.push(curr);
                curr = curr->next;
                cnt++;
            }

            while(s.size() > 0) {
                if(prev == NULL) {
                    prev = s.top();
                    head = prev;
                    s.pop();
                } else {
                    prev->next = s.top();
                    prev = prev->next;
                    s.pop();
                }
            }
        }

        prev->next = NULL;
        return head;
    }
};

// Soltion 3 -
class Solution
{
public:

    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;

        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto node = head;
        for (int i=0; i < k; ++i)
        {
            if ( ! node  )
                return head; // nothing to do list too sort
            node = node->next;
        }

        auto new_head = reverse( head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
    }
};
