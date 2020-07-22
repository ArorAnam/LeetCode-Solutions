class Solution {
public:
    bool checkBounds(int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int idx) {
        if (visited[i][j])
            return false;

        visited[i][j] = true;
        idx++;
        if (idx == word.length())
            return true;
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto dir : dirs) {
            int ii = i + dir.first, jj = j + dir.second;
            if (checkBounds(ii, jj, board.size(), board[0].size()) && board[ii][jj] == word[idx] && dfs(board, visited, word, ii, jj, idx))
                return true;
        }
        
        visited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, visited, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};