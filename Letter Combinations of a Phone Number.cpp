/*

Given a digit string, return all possible letter combinations that the number could represent.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

map<int ,string> mp;

void solve(vector<string> &v,string &s,string digits,int index)
{
    if(index==digits.length())
    {
        v.push_back(s);
        return ;
    }
    char ch=digits[index];
    int x=ch-'0';
    string str=mp[x];
    for(int i=0;i<str.length();++i)
    {
        s.push_back(str[i]);
        solve(v,s,digits,index+1);
        s.pop_back();
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        mp.clear();
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        mp[0]=" ";
        vector<string> v;
        if(digits.length()==0)
            return v;
        string s;
        solve(v,s,digits,0);
        sort(v.begin(),v.end());
        return v;
    }
};
