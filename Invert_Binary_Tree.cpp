/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void invertTreeUtil(TreeNode *root) {
        if (root == NULL)
            return;

        invertTreeUtil(root->left);
        invertTreeUtil(root->right);

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;

        invertTreeUtil(root);

        return root;
    }
};

// Soltion 2 - using queue
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;

        TreeNode *head = root;
        queue<TreeNode*> q;
        q.push(head);

        // DO BFS while doing BFS, keep swapping
        // left and right children
        while (!q.empty()) {
            // pop of the first eleement
            TreeNode* curr = q.front();
            q.pop();

            std::swap(curr->left, curr->right);

            // push left and right children into queue
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return root;
    }
};
