/*

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                int temp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=temp;
                ++low;
                ++mid;
            }
            else if(nums[mid]==1)
                ++mid;
            else
            {
                int temp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=temp;
                --high;
            }
        }
        
    }
};
