/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

bool issafe(vector<vector<char>>& grid,vector<vector<bool>>& visited,int r,int c)
{
    if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1' && !visited[r][c])
        return true;
    return false;
}

void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int r,int c)
{
    visited[r][c]=true;
    int row[4]={-1,0,0,1};
    int col[4]={0,1,-1,0};
    
    for(int k=0;k<4;++k)
    {
        if(issafe(grid,visited,r+row[k],c+col[k]))
            dfs(grid,visited,r+row[k],c+col[k]);
    }
    
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count=0;
        int m=grid.size();
        if(m==0)
            return 0;
        int n=grid[0].size();
        if(m==0 || n==0)
            return 0;
        vector<vector<bool>> visited(m,vector<bool> (n));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
                visited[i][j]=false;
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    ++count;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
};
