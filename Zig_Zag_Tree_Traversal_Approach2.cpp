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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root != nullptr)
            q.push(root);

        bool dir = false;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> lst;

            while (size--) {
                TreeNode *temp = q.front();
                q.pop();

                lst.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }

            if (dir)
                reverse(lst.begin(), lst.end());
            
            res.push_back(lst);
            dir = !dir;
        }
        return res;
    }
};