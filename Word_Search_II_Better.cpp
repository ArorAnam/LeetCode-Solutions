class Solution {
public:
    struct Node{
        Node* child[26];
        int count;
        Node(): count(0){memset(child, 0, sizeof(child));}
    };
    typedef pair<int, int> Grid;
    Grid directions[4] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    void buildTree(Node* root, vector<string>& words){
        Node* cur = nullptr;
        for(string& word: words){
            cur = root;
            for(char c: word){
                int i = (int)(c-'a');
                if(cur->child[i] == 0){
                    cur->child[i] = new Node();
                }
                cur = cur->child[i];

            }
            cur->count ++;
        }
    }
    void DFS(int row, int col, vector<vector<char>>& board, Node* cur, vector<string>& res, string& curw){
        int idx = (int)(board[row][col] - 'a');
        if(cur->child[idx] != 0){
            cur = cur->child[idx];
        }
        else
            return;
        
        curw.push_back(board[row][col]);
        if(cur->count > 0){
            res.push_back(curw);
            cur->count --;
        }
        
        board[row][col] = 0;
        for(auto& d: directions){
            int nr = row + d.first, nc = col + d.second;
            if(nr >= 0 && nr < board.size() &&
              nc >= 0 && nc < board[0].size() &&
              board[nr][nc] != 0){
                DFS(nr, nc, board, cur, res, curw);
            }
        }
        board[row][col] = curw.back();
        curw.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        buildTree(root, words);
        
        vector<string> res;
        string curw;
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[0].size(); ++ j)
                DFS(i, j, board, root, res, curw);
        return res;
    }
};