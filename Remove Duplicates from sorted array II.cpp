/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=2;
        int i=2;
        int n=nums.size();
        if(n==0)
            return 0;
        if(n<=2)
            return n;
        int prev=1;
        int curr=2;
        while(curr<n)
        {
            if(nums[curr]==nums[prev] && nums[curr]==nums[prev-1])
                ++curr;
            else
            {
                ++prev;
                nums[prev]=nums[curr];
                ++curr;
            }
        }
        return prev+1;;
    }
};
