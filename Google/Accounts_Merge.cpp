class UnionFind {
private:
    vector<int> p;
    int numsets;
public:
    UnionFind(int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
        numsets = n;
    }

    bool sameset(int i, int j) { return findset(i) == findset(j); }
    int nums_disjoint_sets() { return numsets; }

    int findset(int i) {
        if (p[i] != i) p[i] = findset(p[i]);
        return p[i];
    }

    void unionset(int i, int j) {
        if (sameset(i, j)) return;
        p[findset(i)] = findset(j);
        numsets--;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email2id;
        unordered_map<string, string> email2name;
        int id = 0;
        UnionFind UF(10001);
        int maxparent = 0;
        for (auto &account: accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (!email2name.count(email)) email2name[email] = name;
                if (!email2id.count(email)) email2id[email] = id++;
                UF.unionset(email2id[email], email2id[account[1]]);
            }
        }

        unordered_map<int, vector<string>> ind2ans;
        for (auto &[email, name] : email2name) {
            int parent = UF.findset(email2id[email]);
            if (!ind2ans.count(parent)) ind2ans[parent].emplace_back(name);
            ind2ans[parent].emplace_back(email);
        }

        vector<vector<string>> ans;
        for (auto &[x, y] : ind2ans) {
            sort(y.begin() + 1, y.end());
            ans.emplace_back(y);
        }

        return ans;
    }
};
