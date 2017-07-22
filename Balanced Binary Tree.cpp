/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


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

int height(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lht=height(root->left);
    int rht=height(root->right);
    return max(lht,rht)+1;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
            return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(fabs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
        
    }
};
