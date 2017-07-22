/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        vector<int> prev;
        prev.push_back(1);
        if(rowIndex==0)
            return prev;
        prev.push_back(1);
        if(rowIndex==1)
            return prev;
        
        for(int i=2;i<=rowIndex;++i)
        {
            res.clear();
            res.push_back(1);
            for(int j=1;j<prev.size();++j)
            {
                res.push_back(prev[j]+prev[j-1]);
            }
            res.push_back(1);
            prev=res;
        }
        return res;
        
    }
};
