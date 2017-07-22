/*

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique

*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int> >vec;
        vector<string> ans(nums.size());
        if(nums.size()==0)
            return ans;
        if(nums.size()==1)
        {ans[0]="Gold Medal";
        return ans;}
        for(int i=0;i<nums.size();++i)
        {
            pair<int,int> p;
            p.first=nums[i];
            p.second=i;
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end());
        int ctr=1;
        for(int i=vec.size()-1;i>=0;--i)
        {
            if(ctr==1)           
            {
                int x=vec[i].second;
                ans[x]="Gold Medal";
                ++ctr;
            }
            else if(ctr==2)
            {
                int x=vec[i].second;
                ans[x]="Silver Medal";
                ++ctr;
            }
            else if(ctr==3)
            {
                int x=vec[i].second;
                ans[x]="Bronze Medal";
                ++ctr;
            }
            else
            {
                int x=vec[i].second;
                ans[x]=to_string(ctr);
                ++ctr;
            }
        }
        return ans;
    }
};
