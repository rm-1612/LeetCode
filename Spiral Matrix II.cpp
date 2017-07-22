/*

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int> > result;
        int i,j;
        for(int i=0;i<n;++i)
        {
            vector<int> v;
            for(int j=0;j<n;++j)
            {
                v.push_back(0);
            }
            result.push_back(v);
        }
        int top=0,bottom=n-1,left=0,right=n-1;
        int dir=1;
        int val=1;
        while(top<=bottom && left<=right)
        {
            if(dir==1)
            {
                for(j=left;j<=right;++j)
                {
                    result[top][j]=val;
                    ++val;
                }
                ++top;
                dir=2;
            }
            else if(dir==2)
            {
                for(i=top;i<=bottom;++i)
                {
                    result[i][right]=val;
                    ++val;
                }
                --right;
                dir=3;
            }
            else if(dir==3)
            {
                for(j=right;j>=left;--j)
                {
                    result[bottom][j]=val;
                    ++val;
                }
                --bottom;
                dir=4;
            }
            else if(dir==4)
            {
                for(i=bottom;i>=top;--i)
                {
                    result[i][left]=val;
                    ++val;
                }
                ++left;
                dir=1;
            }
        }
        return result;
    }
};
