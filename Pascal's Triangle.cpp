/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> prev;
        vector<vector<int> > res;
        if(numRows==0)
            return res;
        int i,n=numRows;
        prev.push_back(1);
        res.push_back(prev);
        for(i=2;i<=n;++i)
        {
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<prev.size();++j)
            {
                v.push_back(prev[j]+prev[j-1]);
            }
            v.push_back(1);
            res.push_back(v);
            prev=v;
        }
        return res;
    }
};
