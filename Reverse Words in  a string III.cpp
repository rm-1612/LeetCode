/*

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string str="";
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==' ')
            {
                reverse(str.begin(),str.end());
                ans=ans+str+" ";
                str.clear();
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        reverse(str.begin(),str.end());
        ans=ans+str;
        return ans;
    }
};
