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

// Soltion 1 :
// T: O(n), S: O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*> mp;

        Node* copy = NULL, *p = head;

        while(p != NULL) {
            copy = new Node(p->val);
            mp[p] = copy;
            p = p->next;
        }

        p = head;
        while(p != NULL) {
            copy = mp[p];
            copy->next = mp[p->next];
            copy->random = mp[p->random];
            p = p->next;
        }

        return mp[head];
    }
};

// Solution 2 -
// T: O(N)
// S: O(1)
class Solution {
public:
    Node * copyRandomList(Node* head) {
        Node* curr = head, *temp;

        while(curr)  {
            temp = curr->next;
            curr->next = new Node(curr->data);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;
        while(curr) {
            if (curr->next)
                curr->next->random = curr->random ?
                                     curr->random->next : curr->random;
            curr = curr->next ? curr->next->next : curr->next;
        }

        Node *orig = head, *copy = head->next;
        temp = copy;
        while(orig && copy) {
            orig->next = orig->next ? orig->next->next : orig->next;

            copy->next = copy->next ? copy->next->next : copy->next;

            orig = orig->next;
            copy = copy->next;
        }

        return temp;
    }
}
