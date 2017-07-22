/*

Given inorder and postorder traversal of a tree, construct the binary tree.

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
TreeNode* build( vector<int>& inorder,vector<int>& postorder,int instart,int inend,int &postindex)
{
    if(instart>inend)
        return NULL;
    TreeNode* root=new TreeNode(postorder[postindex]);
    --postindex;
    if(instart==inend)
        return root;
    int index=search(inorder,root->val,instart,inend);
    root->right=build(inorder,postorder,index+1,inend,postindex);
    root->left=build(inorder,postorder,instart,index-1,postindex);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postindex=n-1;
        return build(inorder,postorder,0,n-1,postindex);
        
    }
};
