class TrieNode {
public:
    vector<TrieNode*> children;
    string word;

    TrieNode() {
        word = "";
        children.resize(26, nullptr);
    }
};

class Solution {
public:
    TrieNode *root;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        //Insert all words into the Trie
        for(auto w : words) {
            insert(w);
        }

        vector<string> res;
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                dfs(board, root, i, j, &res);
            }
        }

        return res;
    }

    void insert(string word) {
        TrieNode *pCrawl = root;

        for(char c : word) {
            int index = c - 'a';
            if(!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();

            pCrawl = pCrawl->children[index];
        }
        pCrawl->word += word;
    }

    void dfs(vector<vector<char>> board, TrieNode *p, int i, int j, vector<string> *res) {
        char c = board[i][j];
        if(c == '#' || !(p->children[c-'a']))
            return;
        
        p = p->children[c-'a'];
        if(!(p->word.empty())) {
            res->emplace_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if(i > 0) dfs(board, p, i-1, j, res);
        if(j > 0) dfs(board, p, i, j-1, res);
        if(i < (board.size() - 1)) dfs(board, p, i+1, j, res);
        if(j < (board[0].size() - 1)) dfs(board, p, i, j+1, res);
        board[i][j] = c;
    }    
};