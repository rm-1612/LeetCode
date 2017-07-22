/*

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double average=0,max_average=INT_MIN;
        for(int i=0;i<k;++i)
        {
            average=average+nums[i];
        }
        double val=average/(float)k;
        if(val>max_average)
            max_average=val;
        int j=0;
        for(int i=k;i<nums.size();++i)
        {
            average=average-nums[j]+nums[i];
            ++j;
            val=average/(float)k;
            if(val>max_average)
                max_average=val;
        }
        return max_average;
    }
};
