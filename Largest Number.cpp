/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

bool compare(string x,string y)
{
    string xy=x.append(y);
    string yx=y.append(x);
    if(xy>yx)
        return true;
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> numbers;
        for(int i=0;i<nums.size();++i)
            numbers.push_back(to_string(nums[i]));
        
        sort(numbers.begin(),numbers.end(),compare);
        string s="";
        for(int i=0;i<numbers.size();++i)
            s=s+numbers[i];
        int i=0;
        while(s[i]=='0' && i<s.length())
            ++i;
       string str="";
        if(i==s.length())
            str="0";
        else
        {
            
        int p=s.length()-i;
        str=s.substr(i,p);
        }
        return str;
    }
};
