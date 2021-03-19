//T: O(N) : since we are looking at all nodes.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        
        stack<TreeNode*> s;
        TreeNode *node = root;
        long prev = LONG_MIN;
        while ( !s.empty() || node != NULL ) {
            while (node != NULL) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if (node->val <= prev) return false;
            prev = node->val;
            node = node->right;
        }
        return true;
    }
};

// Sol - 2
 public boolean isBST(Node root){
        return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    private boolean isBST(Node root, int min, int max){
        if(root == null){
            return true;
        }
        if(root.data <= min || root.data > max){
            return false;
        }
        return isBST(root.left, min, root.data) && isBST(root.right, root.data, max);
    }