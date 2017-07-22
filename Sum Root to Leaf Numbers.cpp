/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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

void path1(TreeNode* root,int path[],int pathlen,int &sum)
{
    if(root==NULL)
        return ;
    path[pathlen]=root->val;
    ++pathlen;
    if(root->left==NULL && root->right==NULL)
    {
        int val=0;
        for(int i=0;i<pathlen;++i)
        {
            val=val*10+path[i];
        }
        sum=sum+val;
        return;
    }
    path1(root->left,path,pathlen,sum);
    path1(root->right,path,pathlen,sum);
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int path[1005],pathlen=0;
        path1(root,path,pathlen,sum);
        return sum;
    }
};
