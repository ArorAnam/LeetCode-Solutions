// Solution 1 - recursive
// T: O(M+N)*2^(M+N/2)
// S: O(M^2+N^2)

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if(p.length() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        else
            return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};


// Solution 2 - DP
// T: O(M*N)
// S: O(M*N)

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> T(s.length()+1, vector<bool>(p.length()+1));

        T[0][0] = true;
        // Deals with patterns like a* or a*b* or a*b*c*
        for(int i=1; i < T[0].size(); i++) {
            if(p[i-1] == '*')
                T[0][i] = T[0][i-2];
        }

        for(int i=1; i < T.size(); i++) {
            for(int j=1; j < T[0].size(); j++) {
                if(p[j-1] == '.' || p[j-1] == s[i-1])
                    T[i][j] = T[i-1][j-1];
                else if(p[j-1] == '*') {
                    T[i][j] = T[i][j-2];
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        T[i][j] = T[i][j] | T[i-1][j];
                }
                else
                    T[i][j] = false;
            }
        }

        return T[s.length()][p.length()];
    }
};
