class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

double ans = INT_MIN;
Node *res;

vector<double> dfs(Node *node) {
    if (!node)
        return {0, 0};

    double currVal = node->val;
    double count = 1;
    for (auto child : node->children) {
        vector<double> temp = dfs(child);
        count += temp[1];
        currVal += temp[0];
    }

    double avg = currVal / count;
    if (count > 1 && avg > ans) {
        ans = avg;
        res = node;
    }

    return {currVal, count};
}

int maximumAverageSubtree(Node* root) {
    if (!root) {
        return  0;
    }

    dfs(root);
    return res->val;
}
