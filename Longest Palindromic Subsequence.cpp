/*

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n=s.length();
        int dp[n][n];
        int i;
        for(i=0;i<n;++i)
            dp[i][i]=1;
        for(int l=2;l<=n;++l)
        {
            for(i=0;i<n-l+1;++i)
            {
                int j=i+l-1;
                if(s[i]==s[j] && l==2)
                    dp[i][j]=2;
                else if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else 
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
