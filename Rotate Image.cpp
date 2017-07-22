/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix.size();++j)
            {
                if(i<j)
                {
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
        
        int left=0;
        int right=matrix.size()-1;
        while(left<=right)
        {
            for(int i=0;i<matrix.size();++i)
            {
                int temp=matrix[i][left];
                matrix[i][left]=matrix[i][right];
                matrix[i][right]=temp;
            }
            ++left;
            --right;
        }
        
    }
};
