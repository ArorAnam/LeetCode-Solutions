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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>();

        int n = maxDepth(root);
        vector<vector<int>> res(n);

        levelOrder(root->left, root->right, res, n-1);

        res[n-1].push_back(root->val);
        return res;
    }

    void levelOrder(TreeNode *pLeft, TreeNode *pRight, vector<vector<int>>& res, int level) {

        if(pLeft != NULL) {
            levelOrder(pLeft->left, pLeft->right, res, level-1);
            res[level-1].push_back(pLeft->val);
        }

        if(pRight != NULL) {
            levelOrder(pRight->left, pRight->right, res, level-1);
            res[level-1].push_back(pRight->val);
        }
    }

    int maxDepth(TreeNode *root) {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};