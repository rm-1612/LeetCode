/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> s1;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                s1.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(s1.empty())
                    return false;
                if(s1.top()!='(')
                    return false;
                s1.pop();
            }
            else if(s[i]=='}')
            {
                if(s1.empty())
                    return false;
                if(s1.top()!='{')
                    return false;
                s1.pop();
            }
            else if(s[i]==']')
            {
                if(s1.empty())
                    return false;
                if(s1.top()!='[')
                    return false;
                s1.pop();
            }
        }
        if(s1.empty())
            return true;
        return false;
    }
};
