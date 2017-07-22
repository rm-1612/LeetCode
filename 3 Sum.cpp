/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > triples;
        sort(nums.begin(),nums.end());
        map<vector<int> ,int > mp;
        int n=nums.size(),i;
        for(i=0;i<n;++i)
        {
            int sum=nums[i];
            int left=i+1,right=n-1;
            while(left<right)
            {
                if(sum+nums[left]+nums[right]<0)
                    ++left;
                else if(sum+nums[left]+nums[right]==0)
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    if(mp.find(v)==mp.end())
                    {mp[v]=1;
                    triples.push_back(v);}
                    ++left;
                    --right;
                }
                else --right;
            }
        }
        return triples;
        
    }
};
