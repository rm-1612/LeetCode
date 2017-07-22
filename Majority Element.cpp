/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int index=0;
        int i;
        int n=nums.size();
        for(i=1;i<nums.size();++i)
        {
            if(nums[i]==nums[index])
            {
                ++count;
                continue;
            }
            if(nums[i]!=nums[index])
            {
                --count;
            }   
            if(count==0)
            {
                index=i;
                count=1;
            }
        }
        count=0;
        for(i=0;i<nums.size();++i)
         {
            if(nums[i]==nums[index])
                ++count;
        }
        if(count>=n/2)
            return nums[index];
    }
};
