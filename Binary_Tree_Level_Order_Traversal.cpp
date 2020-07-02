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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>();

        vector<vector<int>> res(maxDepth(root));

        res[0].push_back(root->val);

        levelOrder(root->left, root->right, res, 1);

        return res;
    }

    void levelOrder(TreeNode *pLeft, TreeNode *pRight, vector<vector<int>>& res, int level) {

        if(pLeft != NULL) {
            res[level].push_back(pLeft->val);
            levelOrder(pLeft->left, pLeft->right, res, level+1);
        }

        if(pRight != NULL) {
            res[level].push_back(pRight->val);
            levelOrder(pRight->left, pRight->right, res, level+1);
        }
    }

    int maxDepth(TreeNode *root) {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};