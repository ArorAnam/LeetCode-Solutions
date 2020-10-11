class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int count = q.size();
            Node *r = nullptr;
            while (count > 0) {
                r = q.front();
                q.pop();
                if (r->left) {
                    r->left->next = r->right;
                    q.push(r->left);
                }
                if (r->right) {
                    if (q.front()) {
                        r->right->next = q.front()->left;
                    }
                    q.push(r->right);
                }
                count--;
            }
            if (r && r->right)
                r->right->next = nullptr;
        }
        return root;
    }
};
