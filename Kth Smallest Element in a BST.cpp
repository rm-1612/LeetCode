/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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

void solve(TreeNode* root,int k,int &ans,int &ctr)
{
    if(root==NULL)
        return ;
    solve(root->left,k,ans,ctr);
    ++ctr;
    if(ctr==k)
        ans=root->val;
    solve(root->right,k,ans,ctr);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int ctr=0;
         solve(root,k,ans,ctr);
        return ans;
    }
};
