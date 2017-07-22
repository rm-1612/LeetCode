/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

void solve(vector<string> &v,string s,int n,int open,int close)
{
    if(close==n)
    {
        v.push_back(s);
        return ;
    }
    else
    {
        if(open>close)
        {
            s.push_back(')');
            solve(v,s,n,open,close+1);
            s.pop_back();
        }
        if(open<n)
        {
            s.push_back('(');
            solve(v,s,n,open+1,close);
            s.pop_back();
        }
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        string s;
        solve(v,s,n,0,0);
        reverse(v.begin(),v.end());
        return v;
    }
};
