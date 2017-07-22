/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        int p[26]={0},i,n=s.length();
        for(i=0;i<n;++i)
        {
            ++p[s[i]-'a'];
        }
        for(i=0;i<n;++i)
        {
            if(p[s[i]-'a']==1)
                break;
        }
        if(i==n)
            return -1;
        return i;
        
    }
};

