/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void find_paths(TreeNode* root,int sum, bool &flag, int path[],int pathlen)
{
    if(root==NULL)
        return ;
    path[pathlen]=root->val;
    ++pathlen;
    if(root->left==NULL && root->right==NULL)
    {
        int sum1=0;
        for(int i=0;i<pathlen;++i)
        {
            sum1+=path[i];
        }
        if(sum1==sum)
            flag=true;
        return;
    }
    find_paths(root->left,sum,flag,path,pathlen);
    find_paths(root->right,sum,flag,path,pathlen);
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        bool flag=false;
        
        int pathlen=0;
        int path[100005];
        find_paths(root,sum,flag,path,pathlen);
        if(flag)
            return true;
        return false;
        
    }
};
