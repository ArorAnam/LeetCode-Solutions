class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& ocean, vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >=m || j < 0 || j >= n) return;
        if (ocean[i][j] == 1) return;
        ocean[i][j] = 1;

        if (i < m - 1 && matrix[i][j] <= matrix[i+1][j])
            dfs(i + 1, j, ocean, matrix);
        if (i > 0 && matrix[i][j] <= matrix[i-1][j])
            dfs(i-1, j, ocean, matrix);

        if (j < n -1 && matrix[i][j] <= matrix[i][j+1])
            dfs(i, j+1, ocean, matrix);
        if (j > 0 && matrix[i][j] <= matrix[i][j-1])
            dfs(i, j-1, ocean, matrix);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> pacific(m, vector<int>(n)), atlantic(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    if (pacific[i][j] == 0)
                        dfs(i, j, pacific, matrix);
                }

                if (i == m - 1 || j == n - 1) {
                    if (atlantic[i][j] == 0)
                        dfs(i, j, atlantic, matrix);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (atlantic[i][j] == 1 && pacific[i][j] == 1)
                    ans.push_back({i, j});
        }

        return ans;
    }
};
