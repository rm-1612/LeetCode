/*

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int i,n=nums.size();
        for(i=0;i<n;++i)
            ans=ans^nums[i];
        return ans;
    }
};
