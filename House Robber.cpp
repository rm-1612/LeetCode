/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        int incl=nums[0];
        int excl=0;
        
        for(int i=1;i<nums.size();++i)
        {
            int old_excl=excl;
            excl=max(excl,incl);
            incl=old_excl+nums[i];
        }
        return max(excl,incl);
    }
};
