// Solutiuon 1:
// Sort the words, by word's length.
// For each word, loop on all possible previous word with 1 letter missing
// if we have seen this previous word, update the longest chain for the
// current word
// Finally return the longest chain.
// T: O(NlogN)
// fo the for loop : O(N*S*S)
//S: O(N*S)
class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for(auto word : words) {
            for(int i = 0; i < word.length(); i++) {
                dp[word] = max(dp[word], dp[word.substr(0, i) + word.substr(i+1)] + 1);
            res = max(res, dp[word]);
            }
        }
        return res;
    }
};

// Solution 2:
// Create a DAG(directed acyclic graph) of the words in the array
// Find out the maximum path length of the graph

class Solution {
    vector<vector<int>> edges;
    vector<int> score;
    int longest(int v) {
        if(score[v] > 0)
            return score[v];
        score[v] = 1;
        for(int b : edges[v]) {
            score[v] = max(score[v], longest(b) + 1);
        }
        return score[v];
    }
public:
    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        edges.clear();
        edges.resize(n);
        score.clear();
        score.resize(n);
        unordered_map<string, int> position;
        for(int i = 0; i < n; i++)
            position[words[i]] = i;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            for(int j = 0; j < (int)s.length(); j++) {
                string temp = s.substr(0, j) + s.substr(j+1);
                auto it = position.find(temp);
                if(it == position.end())
                    continue;
                edges[it->second].push_back(i);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, longest(i));
        }
        return ans;
    }
};
