/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     vector<int> v;
        int m=matrix.size();
        if(m==0)
            return v;
        int n=matrix[0].size();
        if(m==0 || n==0)
            return v;
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        int dir=1;
        while(top<=bottom && left<=right)
        {
            if(dir==1)
            {for(int j=left;j<=right;++j)
                v.push_back(matrix[top][j]);
             dir=2;
            ++top;}
           else  if(dir==2)
            {
                for(int i=top;i<=bottom;++i)
            {
                v.push_back(matrix[i][right]);
                
            }
               dir=3;
            --right;
            }
            else if(dir==3)
            {
                for(int j=right;j>=left;--j)
            {
                v.push_back(matrix[bottom][j]);
                
            }
                dir=4;
            --bottom;
            }
            else if(dir==4)
            {
                for(int i=bottom;i>=top;--i)
            {
                v.push_back(matrix[i][left]);
                
            }
                dir=1;
            ++left;
            }
            
        }
        return v;
    }
};
