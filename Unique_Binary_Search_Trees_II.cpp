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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};

        return treeGenerate(1, n);
    }

    vector<TreeNode*> treeGenerate(int m, int n) {
        vector<TreeNode*> result;

        if(m > n) {
            result.push_back(NULL);
            return result;
        }

        for(int i = m; i <= n; i++) {
            //construct the left subtree
            vector<TreeNode*> lst = treeGenerate(m, i-1);
            //construct the right subtree
            vector<TreeNode*> rst = treeGenerate(i+1, n);
            
            /*now looping through all left and righ subtrees and connecting
                them to the ith root below */
            for(auto l : lst) {
                for(auto r : rst) {
                    TreeNode *curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    result.push_back(curr);
                }
            }
        }
        return result;
    }
};