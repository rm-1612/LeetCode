/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        if(n==0)
            return false;
        if(m==0 && n==0)
            return false;
        int i,j;
        i=0,j=n-1;
        while(i<m)
        {
            if(matrix[i][j]<target)
                ++i;
            else break;
        }
        if(i==m)
            return false;
        if(matrix[i][j]==target)
            return true;
        int p=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
        if(matrix[i][p]==target)
            return true;
        return false;
    }
};
