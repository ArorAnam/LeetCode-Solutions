class Solution {
public:
    void findPaths(int start, int end, vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& currPath) {
        if (start == end) {
            res.push_back(currPath);
        }

        if (graph[start].empty()) {
            //currPath.erase(currPath.size()-1);
            return;
        }

        for (auto vertices : graph[start]) {
            currPath.push_back(vertices);
            findPaths(vertices, end, graph, res, currPath);
            currPath.erase(currPath.end()-1);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        
        if (graph.size() == 0 || graph[0].size() == 0) {
            return res;
        }

        vector<int> currPath;
        currPath.push_back(0);
        findPaths(0, graph.size()-1, graph, res, currPath);

        return res;
    }
};