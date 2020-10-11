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

    void bfs(TreeNode* root, vector<int>& res) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            auto element = q.front();
            TreeNode* v = element.first;
            int level = element.second;
            q.pop();

            // push in res
            if (res.size() < level + 1)
                res.push_back(v->val);
            else
                res[level] = v->val;

            if (v->left) q.push({v->left, level + 1});
            if (v->right) q.push({v->right, level + 1});
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        bfs(root, res);
        return res;
    }
};

// Solution 2 - using DFS and iterating right hand side first,
// and then  taking the value into the map
class Solution {
public:
    typedef long long ll;
    vector<pair<ll, ll>> v;
    map<ll ,ll> mp;

    void dfs(ll id, TreeNode* root) {
        if (root == nullptr) return;
        if (mp[id] == 0) v.push_back({id, root->val});
        mp[id] = 1;
        dfs(id + 1, root->right);
        dfs(id + 1, root->left);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<ll> vv;
        dfs(0, root);
        sort(v.begin(), v.end());
        for (ll i = 0; i < v.size(); i++)
            vv.push_back(v[i].second);

        return vv;
    }
};
