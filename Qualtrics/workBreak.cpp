


















class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        unordered_map<string, bool> x;
        for(string s : wordDict){
            x[s] = true;
        }
        vector<bool> dp(n);
        for(int i = 0;i<n;i++){
            if(x[s.substr(0, i + 1)]){
                dp[i] = true;
            }
            else{
                for(int j = 0;j<i;j++){
                    if(x[s.substr(j + 1, (i - (j + 1) + 1))] && dp[j] == true){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};