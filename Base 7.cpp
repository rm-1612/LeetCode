/*

Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].

*/

class Solution {
public:
    string convertToBase7(int num) {
        int sign=1;
        if(num==0)
            return "0";
        if(num<0)
        {sign=-1;num=num*-1;}
        string str="";
        
        while(num>0)
        {
            int r=num%7;
            char ch=r+'0';
            str=str+ch;
            num/=7;
        }
        if(sign<0)
            str=str+'-';
        reverse(str.begin(),str.end());
        return str;
        
    }
};
