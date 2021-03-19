// Solution 1 --> T: O(n * s)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if (n == 0) return true;
        // I can create a dp table to store results of sub-problems
        // dp[i] will be true if str[0..i] can be segmented into dictionary,
        // otherwise it would be false
        vector< bool > dp(n + 1, false);
        
        // macthed indexes represents the indexes for which dp[i]
        // is true. Initially it has only -1 element is present.
        vector<int> matchedIndexes;
        matchedIndexes.push_back(-1);

        for (int i = 0; i < n; i++) {
            int msize = matchedIndexes.size();

            int flag = 0;
            // check all the subsrinsg from the macthed indexes earlier
            // If any of the subtring macthes set flag = 1
            for (int j = msize - 1; j >= 0; j--) {
                string sb = s.substr(matchedIndexes[j] + 1, i - matchedIndexes[j]);

                if (std::find(wordDict.begin(), wordDict.end(), sb) != wordDict.end()) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                dp[i] = true;
                matchedIndexes.push_back(i);
            }
        }
        return dp[n - 1];
    }
};

// Solution 2 --> T: O(n * dict_size)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        // dp[i] == true means s[0..i-1] can be segmented into dictionary
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;

            for (string x : wordDict) {
                int len = x.size();
                int end = i + len;
                if (end > n) continue;

                if (dp[end]) continue;

                if (s.substr(i, end - 1) == x) 
                    dp[end] = true;
            }
        }
        return dp[n];
    }
};

// Solution 3 --> T: O(N^2)
class Solution {
public:
     bool wordBreakHelper(string s, vector<string>& dict, int start){
        if(start == s.size()) 
            return true;
 
        for (string a : dict){
            int len = a.size();
            int end = start+len;
 
            //end index should be <= string length
            if(end > s.size()) 
                continue;
 
            if(s.substr(start, len) == a)
                if(wordBreakHelper(s, dict, start+len))
                    return true;
        }
 
        return false;
    }

    bool wordBreak(string s, vector<string>& dict) {
        return wordBreakHelper(s, dict, 0);
    }
};

// Solution 4 --> T: O(n^3), S: O(n)
// Recursion with Memoization
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict, int start, vector<bool>& dp) {
        if (start == s.size()) return true;

        if (dp[start]) return dp[start];

        for (int end = start + 1; end <= s.size; end++) {
            if (std::find(wordDict.begin(), wordDict.end(), s.substr(start, end - start))
                    && wordBreak(s, wordDict, end, dp))
                    {
                        return dp[start] = true;
                    }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size());
        return wordBreaK(s, wordDict, 0, dp);
    }
};  

// Solution 5: 
// Using DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && std::find(dict.begin(), dict.end(), s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};