/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/

bool ispalindrome(string str)
{
    int i=0;
    int j=str.length()-1;
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        ++i;
        --j;
    }
    return true;
}

void solve(vector<vector<string> > &res,vector<string> &ans,string s,int start,int end)
{
    if(start>end)
    {
        res.push_back(ans);
        return ;
    }
    for(int i=start;i<=end;++i)
    {
        string str=s.substr(start,i-start+1);
        if(ispalindrome(str))
        {
            ans.push_back(str);
            solve(res,ans,s,i+1,end);
            ans.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
     
        vector<vector<string> > res;
        vector<string> ans;
        solve(res,ans,s,0,s.length()-1);
        return res;
    }
};
