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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto compare = [](ListNode* lhs, ListNode* rhs)
        {
            return lhs->val < rhs->val; 
        };
        
        std::priority_queue<ListNode*, std::vector<ListNode>, decltype(compare)> q(compare);
        
        for (auto l : lists) {
            if (l != NULL)
                q.push(l);
        }

        ListNode* head = new ListNode(0);
        ListNode* point = head;
        while (!q.empty()) {
            point->next = q.top();
            q.pop();
            point = point->next;
            ListNode* next = point->next;
            if (next != NULL) 
                q.push(next);
        }

        return head->next;
    }
};


// Solution 2 : Merge list one by one
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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* ans = h;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                h->next = l1;
                h = h->next;
                l1 = l1->next;
            } else {
                h->next = l2;
                h = h->next;
                l2 = l2->next;
            }
        }

        if (l1 == NULL) h->next = l2;
        if (l2 == NULL) h->next = l1;

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 0) return NULL;

        ListNode* head = mergeTwoLists(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};


// Solution 3 : Merge with Divide And Conquer
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* ans = h;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                h->next = l1;
                h = h->next;
                l1 = l1->next;
            } else {
                h->next = l2;
                h = h->next;
                l2 = l2->next;
            }
        }

        if (l1 == NULL) h->next = l2;
        if (l2 == NULL) h->next = l1;

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return amount > 0 ? lists[0] : NULL;
    }
};