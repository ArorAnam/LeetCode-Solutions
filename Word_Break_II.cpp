class Solution {
public:

    vector<string> wordBreakUtil(string s, vector<string>& wordDict, map<string, vector<string>> memo ) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        vector<string> results;

        if (s.length() == 0) {
            // Base Case
            results.add("");
            return results;
        }

        // break the string apart and append the substrings tp the first word(s)
        for (auto word : wordDict) {
            if (s.rfind(word, 0) == 0) {
                string sub = s.substr(word.length() + 1);
                vector<string> subStrings = wordBreakUtil(sub, wordDict, memo);

                for (auto subString : subStrings) {
                    string optionalSpace = subString.empty() ? "" : " ";
                    results.push_back(word + optionalSpace);
                }
            }
        }

        memo.insert({s, results});
        return results;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        map<string, vector<string>> memo;
        return wordBreakUtil(s, wordDict, memo);

    }
};