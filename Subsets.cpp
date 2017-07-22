/*

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > result;
        map<vector<int>,int> mp;
        int n=nums.size();
        for(int i=0;i<pow(2,n);++i)
        {
            vector<int> v;
            for(int j=0;j<n;++j)
            {
                if(i & (1<<j))
                {
                    v.push_back(nums[j]);
                }
            }
            if(mp.find(v)==mp.end())
            result.push_back(v);
            mp[v]=1;
        }
        return result;
        
    }
};
