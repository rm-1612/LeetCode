/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number
*/

class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;
        while(n>1)
        {
            int num=n;
            int sum=0;
            while(num>0)
            {
                int r=num%10;
                sum=sum+r*r;
                num=num/10;
            }
            n=sum;
            if(mp.find(n)!=mp.end())
                return false;
            mp[n]=1;
        }
        return true;
    }
};
