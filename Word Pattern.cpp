/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space

*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        map<char,string> mp;
        vector<string> v;
        string s="";
        for(int i=0;i<str.length();++i)
        {
            if(str[i]==' ')
            {
                v.push_back(s);
                s="";
            }
            else
            {
                s=s+str[i];
            }
        }
        v.push_back(s);
        map<string,char> mp1;
        if(v.size()!=pattern.length())
            return false;
        for(int i=0;i<pattern.length();++i)
        {
            if(mp.find(pattern[i])==mp.end())
            {
                if(mp1.find(v[i])!=mp1.end())
                    return false;
                mp[pattern[i]]=v[i];
                mp1[v[i]]=pattern[i];
            }
            else 
            {
                string p=mp[pattern[i]];
                if(p!=v[i])
                    return false;
            }
        }
        return true;
    }
};
