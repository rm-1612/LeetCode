/*

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i,n=nums.size();
        if(n<=2)
            return false;
        int left[n],right[n];
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(i=1;i<n;++i)
        {
            left[i]=min(left[i-1],nums[i]);
        }
        for(i=n-2;i>=0;--i)
        {
            right[i]=max(right[i+1],nums[i]);
        }
        for(i=1;i<n-1;++i)
        {
            if(left[i]<nums[i] && nums[i]<right[i])
                return true;
        }
        return false;
    }
};
