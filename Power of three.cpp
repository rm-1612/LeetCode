/*

Given an integer, write a function to determine if it is a power of three.

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return false;
        int num=n;
        while(num%3==0)
        {
            num=num/3;
        }
        if(num==1)
            return true;
        return false;
        
    }
};
