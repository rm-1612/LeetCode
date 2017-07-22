/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
int search(vector<int>& inorder,int val,int low,int high)
{
    for(int i=low;i<=high;++i)
    {
        if(inorder[i]==val)
            return i;
    }
    return -1;
}
TreeNode* build(vector<int>& preorder, vector<int>& inorder,int instart,int inend,int &preindex)
{
    if(instart>inend)
        return NULL;
    TreeNode* root=new TreeNode(preorder[preindex]);
    ++preindex;
    if(instart==inend)
        return root;
    int index=search(inorder,root->val,instart,inend);
    root->left=build(preorder,inorder,instart,index-1,preindex);
    root->right=build(preorder,inorder,index+1,inend,preindex);
    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size()-1;
        int preindex=0;
        return build(preorder,inorder,0,n,preindex) ;
    }
};
