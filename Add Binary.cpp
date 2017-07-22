/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i,j,m=a.length(),n=b.length();
        i=m-1;
        j=n-1;
        string str="";
        int carry=0;
        while(i>=0 && j>=0)
        {
            int x= carry+(a[i]-'0')+(b[j]-'0');
            char ch= '0'+x%2;
            str=str+ch;
            carry=x/2;
            --i;
            --j;
        }
        while(i>=0)
        {
            int x= carry+(a[i]-'0');
            char ch= '0'+x%2;
            str=str+ch;
            carry=x/2;
            --i;
        }
        while(j>=0)
        {
            int x= carry+(b[j]-'0');
            char ch= '0'+x%2;
            str=str+ch;
            carry=x/2;
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
