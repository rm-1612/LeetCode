/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int large=0;
        int i;
        for(int i=0;i<s.length();++i)
        {
            ++mp[s[i]];
        }
        int count=0;
        for(i=0;i<s.length();++i)
        {
            if(mp[s[i]]>0)
            {
                if((mp[s[i]])%2==0)
                    count=count+mp[s[i]];
                else 
                {
                    if(large==0)
                    {count=count+mp[s[i]];++large;}
                    else count=count+mp[s[i]]-1;
                }
            }
            mp[s[i]]=0;
        }
        return count;
    }
};
