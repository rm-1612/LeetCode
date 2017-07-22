/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        TreeNode* current=root;
        stack<TreeNode*> s;
        int done=0;
        while(!done)
        {
            if(current!=NULL)
            {
                s.push(current);
                current=current->left;
            }
            else
            {
                if(s.empty()==false)
                {
                    current=s.top();
                    s.pop();
                    v.push_back(current->val);
                    current=current->right;
                }
                else done=1;
            }
        }
        return v;
    }
};
