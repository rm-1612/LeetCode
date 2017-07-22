/*

Description:

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        bool prime[n];
        for(int i=0;i<n;++i)
            prime[i]=true;
        prime[1]=false;
        prime[0]=false;
        for(int i=2;i<=sqrt(n);++i)
        {
            if(prime[i])
            for(int j=2*i;j<n;j+=i)
            {
                prime[j]=false;
            }
        }
        int count=0;
        int i;
        for(i=0;i<n;++i)
        {
            if(prime[i])
                ++count;
        }
        return count;
        
        
    }
};
