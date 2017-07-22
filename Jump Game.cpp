/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int max_reach=nums[0];
        if(nums.size()<=1)
            return true;
        if(max_reach==0)
            return false;
        int steps=nums[0];
        int jumps=1;
        for(int i=1;i<n;++i)
        {
            if(i+nums[i]>max_reach)
            {
                max_reach=i+nums[i];
            }
            --steps;
            if(steps==0 && i==n-1)
                return true;
            if(steps==0)
            {
                ++jumps;
                steps=max_reach-i;
                if(steps<=0)
                    return false;
            }
        }
        return true;
        
    }
};
