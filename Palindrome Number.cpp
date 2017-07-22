/*

Determine whether an integer is a palindrome. Do this without extra space.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        
        int num=0;
        int n=x;
        while(n>0)
        {
            num=num*10+n%10;
            n=n/10;
        }
        if(num==x)
            return true;
        return false;
        
    }
};
