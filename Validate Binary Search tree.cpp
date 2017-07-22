/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

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

bool check(TreeNode* root,TreeNode* l,TreeNode* r)
{
    if(root==NULL)
        return true;
    if(l!=NULL && root->val<l->val)
        return false;
    if(r!=NULL && root->val > r->val)
        return false;
    return check(root->left,l,root) && check(root->right,root,r);
}

void inorder(TreeNode* root,bool &flag,TreeNode* &prev)
{
    if(root==NULL)
        return ;
    inorder(root->left,flag,prev);
    if(prev!=NULL && root->val<=prev->val)
    {
        flag=flag & false;
    }
    prev=root;
    inorder(root->right,flag,prev);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        TreeNode* prev=NULL;
        inorder(root,flag,prev);
        return flag;
        
    }
};
