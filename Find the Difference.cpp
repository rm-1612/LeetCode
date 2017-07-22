/*

Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.

*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int p[26]={0};
        int q[26]={0};
        for(int i=0;i<s.length();++i)
            ++p[s[i]-'a'];
        for(int i=0;i<t.length();++i)
            ++q[t[i]-'a'];
        char ch;
        for(int i=0;i<26;++i)
        {
            if(p[i]!=q[i])
            {
                ch=i+'a';
            }
        }
        return ch;
    }
};
