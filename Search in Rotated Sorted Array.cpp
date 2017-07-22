/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

int bin(vector<int>& nums)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid>low && nums[mid]<nums[mid-1])
            return mid;
        if(mid<high && nums[mid]>nums[mid+1])
            return mid+1;
        if(nums[mid]>nums[low])
            low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int bin_search(vector<int> &nums,int low,int high,int target)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            high=mid-1;
        else low=mid+1;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot;
        if(nums.size()==0)
            return -1;
        if(nums[0]<nums[nums.size()-1])
            pivot=0;
        else pivot=bin(nums);
        int p;
        if(target>=nums[pivot] && target<=nums[nums.size()-1])
        {
            p=bin_search(nums,pivot,nums.size()-1,target);
        }
        else 
        {
            p=bin_search(nums,0,pivot,target);
        }
        return p;
    }
};
