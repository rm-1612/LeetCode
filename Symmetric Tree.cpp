/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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

bool ismirror(TreeNode* root1,TreeNode* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1!=NULL && root2!=NULL && root1->val==root2->val && ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left))
        return true;
    return false;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
};
