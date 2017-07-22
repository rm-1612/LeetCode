/*

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

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
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
void diff(TreeNode* root,int &min_value, TreeNode* &prev)
{
    if(root==NULL)
        return ;
    diff(root->left,min_value,prev);
    if(prev!=NULL)
    {
        min_value=min(fabs(root->val-prev->val),min_value);
    }
    prev=root;
    diff(root->right,min_value,prev);
}

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int min_value=INT_MAX;
        TreeNode* prev=NULL;
        diff(root,min_value,prev);
        return min_value;
    }
};
