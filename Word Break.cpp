/*

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        bool dp[n+1];
        int i=0,j;
        map<string,int> mp;
        if(wordDict.size()==0)
            return false;
        for(i=0;i<wordDict.size();++i)
        {
            mp[wordDict[i]]=1;
        }
        memset(dp,false,sizeof(dp));
        for(i=1;i<=n;++i)
        {
            if(dp[i]==false && mp[s.substr(0,i)]==1)
                dp[i]=true;
            if(dp[i]==true)
            {
                if(i==n)
                return true;
                for(j=i+1;j<=n;++j)
            {
                if(dp[j]==false && mp[s.substr(i,j-i)]==1)
                    dp[j]=true;
                if(dp[j]==true && j==n)
                    return true;
            }
            }
            
            
        }
        return false;
        
    }
};
