class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;

        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};

//Another solution
/*
double ans=1, i=2*n;
		//using formula directly i.e for value=n, number of trees possible= ((2n)C(n))/(n+1)
		//calculating numerator (2n)C(n) that is equal to ((2n)*(2n-1)*...n terms) / (n*(n-1)*...*1)

		for(int j=1; j<=n; i--,j++){ // i goes from 2n to n terms and j goes from 1 to n
			ans*= i/j;
		}

		return ans/(n+1);
*/