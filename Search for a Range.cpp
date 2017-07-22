/*

Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

int low_index(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target && (mid==0 || nums[mid-1]<target))
            return mid;
        else if(nums[mid]<target)
            low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int high_index(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target && (mid==nums.size()-1 || nums[mid+1]>target))
            return mid;
        else if(nums[mid]>target)
            high=mid-1;
        else low=mid+1;
    }
    return -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result;
        int p=low_index(nums,target);
        int q=high_index(nums,target);
        result.push_back(p);
        result.push_back(q);
        return result;
        
    }
};
