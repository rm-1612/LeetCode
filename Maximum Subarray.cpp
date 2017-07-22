/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_sum=0;
        int n=nums.size();
        int ctr=0;
        int large=INT_MIN;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<0)
                ++ctr;
        }
        if(ctr==n)
        {
            for(int i=0;i<n;++i)
            {
                if(nums[i]>large)
                    large=nums[i];
            }
                return large;
        }
        for(int i=0;i<nums.size();++i)
        {
            sum=sum+nums[i];
            if(sum<0)
            {
                sum=0;
            }
            if(sum>max_sum)
                max_sum=sum;
        }
        return max_sum;
    }
};
