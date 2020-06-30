class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndofWord;

    TreeNode() {
        isEndofWord = fasle;
        children.resize(26, nullptr);
    };
};

class Trie {
public:
    /** Initialize your data structure here. */
    TreeNode *root;

    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *pCrawl = root;

        for(char c : word) {
            int index = c - 'a';
            if(!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();

            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *pCrawl = root;

        for(char c : word) {
            int index = c - 'a';
            if(!pCrawl->children[index])
                return false;
            
            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL && pCrawl->isEndofWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct TreeNode *pCrawl = root;

        for(char c : prefix) {
            int index = c - 'a';
            if(!pCrawl->children[index])
                return false;
            
            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */