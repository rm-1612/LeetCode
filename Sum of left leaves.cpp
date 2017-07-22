/*

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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

void sum_left(TreeNode* root,bool isleft,int &sum)
{
    if(root==NULL)
        return ;
    if(isleft && root->left==NULL && root->right==NULL)
        sum=sum+root->val;
    sum_left(root->left,true,sum);
    sum_left(root->right,false,sum);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
       int sum=0;
        bool isleft=false;
        sum_left(root,isleft,sum);
        return sum;
    }
};
