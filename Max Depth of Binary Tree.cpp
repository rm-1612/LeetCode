/*

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};
