/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int f[n+1];
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=n;++i)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
};
