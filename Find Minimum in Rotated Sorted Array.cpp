/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

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
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int i,n=nums.size();
        if(nums[0]<nums[n-1])
            return nums[0];
        int p=bin(nums);
        return nums[p];
    }
};
