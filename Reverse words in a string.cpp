/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

*/

class Solution {
public:
    void reverseWords(string &s) {
        
        int i=0;
        int n=s.length();
        vector<string> vec;
        string str="";
        for(i=0;i<n;)
        {
            if(s[i]==' ')
            {
                while(s[i]==' ' && i<s.length())
                    ++i;
            }
            else 
            {
                while(s[i]!=' ' && i<s.length())
                {
                    str=str+s[i];
                    ++i;
                }
                vec.push_back(str);
                str="";
            }
        }
        if(str!="")
        vec.push_back(str);
        string ans="";
        if(vec.size()==0)
        {
            s=ans;
            return ;
        }
        ans=ans+vec[vec.size()-1];
        for(int i=vec.size()-2;i>=0;--i)
        {
            ans=ans+" "+vec[i];
        }
        s=ans;
        
    }
};
