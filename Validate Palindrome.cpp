/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(!isdigit(s[i]) && !isalpha(s[i]))
                ++i;
            else if(!isdigit(s[j]) && !isalpha(s[j]))
                --j;
            else 
            {
                if(isalpha(s[i]) && isalpha(s[j]))
                {
                    if(tolower(s[i])!=tolower(s[j]))
                        return false;
                }
                else if(s[i]!=s[j])
                    return false;
                ++i;
                --j;
            }
        }
        return true;
    }
};
