/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
            return 0;
        int dp[m][n];
        int i,j;
        for(i=0;i<m;++i)
            dp[i][0]=1;
        for(j=0;j<n;++j)
            dp[0][j]=1;
        
        for(i=1;i<m;++i)
        {
            for(j=1;j<n;++j)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};
