/*

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int i,j;
        for(i=0;i<n;i+=2*k)
        {
            j=i+k-1;
            if(j>=n)
            {
                j=n-1;
                int left=i;
                int right=j;
                while(left<=right)
                {
                    char ch=s[right];
                    s[right]=s[left];
                    s[left]=ch;
                    ++left;
                    --right;
                }
                break;
            }
            else 
            {
                int left=i;
                int right=j;
                while(left<=right)
                {
                    char ch=s[right];
                    s[right]=s[left];
                    s[left]=ch;
                    ++left;
                    --right;
                }
            }
        }
        return s;
        
    }
};
