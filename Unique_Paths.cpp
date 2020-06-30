class Solution {
public:
    int uniquePaths(int m, int n) {
        //return calcPaths(m, n);

        int dp[n][m];  

        // count for paths to reach any cell in the first 
        // column is 1
        for (int i=0; i<n; i++)
            dp[i][0] = 1;

        // Count of paths to reach any cell in the first
        // row is 1
        for (int j=0; j<m; j++)
            dp[0][j] = 1;

        // Calculate count of paths for other cells
        // bottomm up approach
        for(int i = 1; i<n; i++) {
            for(int j=1; j< m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }

    // int calcPaths(int m, int n) {
    //     if (m == 1 || n == 1)
    //         return 1;
        
    //     return calcPaths(m-1, n) + calcPaths(m, n-1);
    // }
};