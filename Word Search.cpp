/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

bool issafe(int row,int col,vector<vector<char>>& board)
{
    int m=board.size();
    int n=board[0].size();
    if(row>=0 && row<m && col>=0 && col<n )
        return true;
    return false;
}

bool dfs(vector<vector<char>>& board, string word,int index,int r,int c)
{
    if(r>board.size() || c>board[0].size() || r<0 || c<0)
        return false;
    
    if(board[r][c]==word[index] && index==word.length()-1)
        return true;
    
    if(board[r][c]!=word[index])
        return false;
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    char temp=board[r][c];
    board[r][c]='#';
    for(int k=0;k<4;++k)
    {
        if(issafe(r+row[k],c+col[k],board) && dfs(board,word,index+1,r+row[k],c+col[k]))
            return true;
    }
    board[r][c]=temp;
    return false;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0)
            return true;
        char ch=word[0];
        int n=board[0].size();
        int m=board.size();
        if(m==0 || n==0)
            return false;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i][j]==ch)
                {
                    if(dfs(board,word,0,i,j))
                        return true;
                }
            }
        }
        return false;
        
    }
};
