/*

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

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
bool isidentical(TreeNode* s,TreeNode* t)
{
    if(s==NULL && t==NULL)
        return true;
    if(s==NULL)
        return false;
    if(t==NULL)
        return false;
    if(s->val==t->val && isidentical(s->left,t->left) && isidentical(s->right,t->right))
        return true;
    return false;
}

void preorder(TreeNode* s,TreeNode* t,bool &flag)
{
    if(s==NULL)
    {
        return;
    }
    if(isidentical(s,t))
        flag=true;
    preorder(s->left,t,flag);
    preorder(s->right,t,flag);
}

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        bool flag=false;
        
        preorder(s,t,flag);
        return flag;
        
    }
};
