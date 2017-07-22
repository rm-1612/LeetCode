/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        string str="";
        string prev="";
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==' ' && (i!=s.length()-1 && s[i+1]!=' '))
            {
                str="";
            }
            else if(s[i]!=' ')
            {
                str=str+s[i];
            }
        }
        return str.length();
        
        
    }
};
