/*

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> lis;
        int i,n=nums.size();
        for(i=0;i<n;++i)
        {
            if(lis.size()==0)
                lis.push_back(nums[i]);
            else
            {
                int p=lis[lis.size()-1];
                if(nums[i]>p)
                    lis.push_back(nums[i]);
                else
                {
                    int x=upper_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                    if(lis[x-1]==nums[i])
                        continue;
                    lis[x]=nums[i];
                }
            }
        }
        return lis.size();
    }
};
