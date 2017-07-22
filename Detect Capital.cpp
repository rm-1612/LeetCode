/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()<=1)
            return true;
       int state;
        if(isupper(word[0]) && isupper(word[1]))
            state=1;
        else if(isupper(word[0]) && islower(word[1]))
            state=2;
        else if(islower(word[0]) && islower(word[1]))
            state=3;
        else return false;
        for(int i=2;i<word.length();++i)
        {
            if(isupper(word[i]) && (state==2 || state==3))
                return false;
            if(islower(word[i]) && state==1)
                return false;
        }
        return true;
    }
};
