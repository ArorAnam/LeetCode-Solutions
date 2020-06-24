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
        return validator(root, INT_MIN, INT_MAX);      
    }

    bool validator(TreeNode *root, double min, double max) {
        if(root == NULL)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        bool isLeftBST = validator(root->left, min, root->val);
        bool isRightBST = validator(root->right, root->val, max);

        if (!isLeftBST || !isRightBST)
            return false;
        
        return true;
    }
    
};