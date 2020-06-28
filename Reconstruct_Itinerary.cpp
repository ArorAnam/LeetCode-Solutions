class Solution {
private:
    map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> ans;

    void dfs(string src) {
        while(!adj[src].empty()) {
            string s = adj[src].top();
            adj[src].pop();
            dfs(s);
        }
        ans.insert(ans.begin(), src);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear(), ans.clear();
        for (auto k : tickets) {
            adj[k[0]].push(k[1]);
        }

        dfs("JFK");
        return ans;
    }
};