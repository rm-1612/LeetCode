/*

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> v;
        if(root==NULL)
            return v;
        s1.push(root);
        while(s1.empty()==false)
        {
            TreeNode* temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
        while(s2.empty()==false)
        {
            v.push_back((s2.top())->val);
            s2.pop();
        }
        return v;
        
    }
};
