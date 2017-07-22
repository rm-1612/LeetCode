/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y"

*/

class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(tolower(s[i])!='a' && tolower(s[i])!='e' && tolower(s[i])!='i' && tolower(s[i])!='o' && tolower(s[i])!='u')
            {
                ++i;
            }
            else if(tolower(s[j])!='a' && tolower(s[j])!='e' && tolower(s[j])!='i' && tolower(s[j])!='o' && tolower(s[j])!='u')
                --j;
            else
            {
                char ch=s[i];
                s[i]=s[j];
                s[j]=ch;
                ++i;--j;
            }
        }
        return s;
    }
};
