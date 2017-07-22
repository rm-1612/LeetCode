/*

Given an integer, write a function to determine if it is a power of two.

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        int x=log2(n);
        if(pow(2,x)!=n)
            return false;
        return true;
    }
};
