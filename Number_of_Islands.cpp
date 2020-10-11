class Solution {

    bool isSafe(vector<vector<char>>& grid, int row, int col, vector<vector<bool>> visited) {
        return ((row >= 0) && (row < grid.size()) && (col >= 0) &&
                (col < grid[0].size()) &&
                (grid[row][col] == '1' && !visited[row][col]));
    }

    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>> visited) {
        static int rowNbr[] = { -1, 1, 0, 0};
        static int colNbr[] = { 0, 0, -1, 1};

        visited[row][col] = true;

        // recur for all connected neighbours
        for (int k = 0; k < 4; k++)
            if (isSafe(grid, row + rowNbr[k], col + colNbr[k], visited))
                dfs(grid, row + rowNbr[k], col + colNbr[k], visited);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    ++count;
                }

        return count;
   }
};

// soltion 2
// O=(m*n)
class Solution {

    void merge(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i > m || j < 0 || j > n || grid[i][j] != '1')
            return;

        grid[i][j] = 'X';

        merge(grid, i-1, j);
        merge(grid, i+1, j);
        merge(grid, i, j-1);
        merge(grid, i, j+1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    merge(grid, i ,j);
                }
            }
        }
        return count;
    }
};

// Solution 3
class Solution {
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};

  void dfs(vector<vector<char>>& grid, int x, int y) {
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
        return;

    grid[x][y] = '0';
    for(int k = 0; k < 4; ++k)
        dfs(grid, x + dx[k], y + dy[k]);
  }

  void bfs(vector<vector<char>> &grid, int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    grid[x][y] = '0';
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int new_x = dx[k] + xx;
            int new_y = dy[k] + yy;
            if (!(new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() ||
                '0' == grid[new_x][new_y])) {
                grid[new_x][new_y] = '0';
                q.emplace(new_x, new_y);
            }
        }
    }
}

 public:

  int numIslands(vector<vector<char>> &grid) {
      int count = 0;
      for (int i = 0; i < grid.size(); ++i) {
          for (int j = 0; j < grid[i].size(); ++j) {
              if ('1' == grid[i][j]) {
                  ++count;
                  dfs(grid, i, j);
				  // bfs(grid, i, j);
              }
          }
      }
      return count;
  }
};
