#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;

    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        root->children.clear();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == NULL) {
                node->children[c - 'a'] = new TrieNode();
            }

            node = node->children[c - 'a'];
        }

        node->isWord = true;
    }

    bool match(string word, int depth, TrieNode* node) {
        if (depth == word.length())
            return node->isWord;

        if (word[depth] != '.') {
            return (node->children[word[depth] - 'a'] != NULL &&
                        match(word, depth + 1, node->children[word[depth] - 'a']));

        }
        else {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL && match(word, depth + 1, node->children[i]))
                    return true;
            }
        }
        return false;
    }


    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(word, 0, root);
    }
};

int main() {
     WordDictionary* obj = new WordDictionary();
     obj->addWord("dad");
     bool param_2 = obj->search("dad");

     cout << param_2;

     return 0;
}
