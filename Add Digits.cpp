/*

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

*/

class Solution {
public:
    int addDigits(int num) {
        while(num>9)
        {
            int n=num;
            int sum=0;
            while(n>0)
            {
                sum=sum+n%10;
                n=n/10;
            }
            num=sum;
        }
        return num;
    }
};
