/*

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int i,n=nums.size();
        int left[n],right[n];
        vector<int> output(n);
        left[0]=1;
        for(i=1;i<n;++i)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        right[n-1]=1;
        for(i=n-2;i>=0;--i)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for(i=0;i<n;++i)
            output[i]=left[i]*right[i];
        return output;
    }
};
