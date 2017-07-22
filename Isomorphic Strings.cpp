/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,char> mp1;
        for(int i=0;i<s.length();++i)
        {
            if(mp.find(s[i])==mp.end())
            {
                if(mp1.find(t[i])!=mp1.end())
                    return false;
                mp1[t[i]]=s[i];
                mp[s[i]]=t[i];
            }
            else
            {
                char ch=mp[s[i]];
                if(t[i]!=ch)
                    return false;
            }
        }
        return true;
    }
};
