/*

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i,j,m=num1.length(),n=num2.length();
        i=m-1;
        j=n-1;
        int carry=0;
        string str="";
        while(i>=0 && j>=0)
        {
            int x=carry+(num1[i]-'0')+(num2[j]-'0');
            char ch=x%10+'0';
            str=str+ch;
            carry=x/10;
            --i;
            --j;
        }
        while(i>=0 )
        {
            int x=carry+(num1[i]-'0');
            char ch=x%10+'0';
            str=str+ch;
            carry=x/10;
            --i;
        }
        while(j>=0)
        {
            int x=carry+(num2[j]-'0');
            char ch=x%10+'0';
            str=str+ch;
            carry=x/10;
            --j;
        }
        if(carry>0)
        {
            char ch=carry+'0';
            str=str+ch;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
