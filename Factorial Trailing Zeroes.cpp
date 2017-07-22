/*

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

class Solution {
public:
    int trailingZeroes(int n) {
        long long int x=5;
        if(n<0)
            return -1;
        long long int ctr=0;
     while((n/x)>=1)
     {
         ctr=ctr+(n/x);
         x=x*5;
     }
        return ctr;
    }
};
