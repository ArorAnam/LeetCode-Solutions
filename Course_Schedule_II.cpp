class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<bool> visited;

    void addEdge(int u, int v) {
        for (int j : adj[v]) {
            if (j == u)
                return vector<int>();
        }
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    bool dfs(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u);
            for (int j : adj[u]) {
                if (j == v)
                    return false;
            }
        }
        ans.push_back(v);
    }   

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        adj.resize(numCourses);
        for(auto k : prerequisites) {
            addEdge(k[1], k[0]);
        }

        visited.assign(numCourses, false);
        ans.clear();

        for(int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                bool chk = dfs(i);
                if (chk == false)
                    return vector<int>();
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};