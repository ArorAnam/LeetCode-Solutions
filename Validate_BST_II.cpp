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
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return isBSTUtil(root, prev);
    }

    bool isBSTUtil(struct TreeNode* root, struct TreeNode* prev) {
        if (root) {
            if (!isBSTUtil(root->left, prev))
                return false;

            // allows only distinct values
            if (prev != NULL && root->val <= prev->val)
                return false;

            prev = root;

            return isBSTUtil(root->right, prev);
        }

        return true;
    }
};