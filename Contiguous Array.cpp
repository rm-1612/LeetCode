/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i,n=nums.size();
        int len;
        int max_len=0;
        for(i=0;i<n;++i)
            if(nums[i]==0)
                nums[i]=-1;
        int sum=0;
        map<int,int> mp;
        for(i=0;i<n;++i)
        {
            sum=sum+nums[i];
            if(sum==0)
            {
                len=i+1;
                if(len>max_len)
                {
                    max_len=len;
                }
                continue;
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
            else
            {
                int x=mp[sum];
                len=i-x;
                if(len>max_len)
                    max_len=len;
            }
        }
        return max_len;
    }
};
