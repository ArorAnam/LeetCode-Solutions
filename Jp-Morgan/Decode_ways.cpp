
// SOlution 1 - recursive + memoization
class Solution {
    vector<int> dp;
public:
    int solve(string s, int i, int n) {
        if (i == n) return 1;
        if (i > n) return 0;
        if (dp[i] != -1) return dp[i];
        dp[i] = 0;
        if (s[i] > '0') dp[i] = solve(s, i + 1, n);
        // else dp[i] = 0
        if (i < n - 1 && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')))
            dp[i] += solve(s, i + 2, n);
        // else dp[i + 1] = 0

        return dp[i];
    }

    int numDecodings(string s) {
        int n = s.length();
        dp.assign(n + 1, -1);
        if (n == 0 || s[0] == '0') return 0;
        if (n == 1) return 1;

        return solve(s, 0, n);
    }
};


// Solution 2 : O(n)
// dp[i] = dp[i-1] + dp[i - 2]
class Solution {
    vector<int> dp;
public:
    int numDecodings(string s) {
        int n = s.length();
        dp.resize(n + 1);
        dp[0] = 1;
        if (s[0] == '0')
            return 0;
        dp[1] = 1;

        for (int i = 1; i < s.length(); i++) {
            char c = s[i];
            char p = s[i - 1];

            if (c == '0' && (p == '0' || p > '2')) return 0;

            if (p == '0')
                dp[i + 1] = dp[i];
            else if (p == '1') {
                if (c == '0')
                    dp[i + 1] = dp[i - 1];
                else
                    dp[i + 1] = dp[i - 1] + dp[i];
            }
            else if (p == '2') {
                if(c == '0')
                    dp[i + 1] = dp[i - 1];
                else if (c <= '6')
                    dp[i + 1] = dp[i] + dp[i - 1];
                else
                    dp[i + 1] = dp[i];
            }
            else
                dp[i + 1] = dp[i];
        }

        return dp[s.length()];
    }
};


// Soltion 3 - O(n)
bool is_valid(char c1, char c2){
     return c1 != '0' && (c1-'0')*10+(c2-'0') <= 26;
 }

 int numDecodings(string s) {
     int last = 1;
     int second_last = 0;

     for(int i=1; i<=s.size(); i++){
         int curr = 0;
         if(s[i-1] != '0')
             curr+=last;
         if(i>1 && is_valid(s[i-2], s[i-1]))
             curr+=second_last;
         second_last = last;
         last = curr;
     }
     return last;
 }
