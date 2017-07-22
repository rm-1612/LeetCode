/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    
    */
    
 class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int sum=0;
        int diff=INT_MAX,i,j,k,min_diff=INT_MAX,c_sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(i=0;i<n;++i)
        {
            j=i+1;
            k=n-1;
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                diff=sum-target;
                if(diff==0)
                    return sum;
                else if(diff<0)
                {
                    ++j;
                }
                else --k;
                if(fabs(diff)<min_diff)
                {
                    min_diff=fabs(diff);
                    c_sum=sum;
                }
            }
        }
        return c_sum;
        
    }
};
