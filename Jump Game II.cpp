/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int max_reach=nums[0];
        int steps=nums[0];
        int n=nums.size();
        int jumps=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]+i>max_reach)
                max_reach=i+nums[i];
            --steps;
            if(steps==0 && i<n-1)
            {
                ++jumps;
                steps=max_reach-i;
            }
        }
        return jumps;
        
    }
};
