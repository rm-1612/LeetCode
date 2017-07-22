/*

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i,n=digits.size();
        int carry=1;
        for(i=n-1;i>=0;--i)
        {
            
            int x=digits[i]+carry;
            digits[i]=(x)%10;
            carry=(x)/10;
        }
        vector<int> v;
        if(carry>0)
        {
            v.push_back(carry);
            for(int i=0;i<n;++i)
                v.push_back(digits[i]);
            return v;
        }
        return digits;
    }
};
