class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> hash(26);
        for(int i=0; i<t.size(); ++i) {
            hash[t[i] - 'a'].push_back(i);
        }
        return SubsequenceCheck(s, hash);
    }

    bool SubsequenceCheck(string s, vector<vector<int>> &t) {
        int i = 0;
        for(char c: s) {
            auto indices = t[c -'a'];
            auto it = lower_bound(indices.begin(), indices.end(), i);
            if(it == indices.end())
                return false;
            else
                i = *it + 1;
        }
        return true;
    }
};