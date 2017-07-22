/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int> > ans;
        if(root==NULL)
            return ans;
        int nodecount=0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            nodecount=q.size();
            vector<int> v;
            
            while(nodecount>0)
            {
                TreeNode* t=q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
                --nodecount;
            }
            ans.push_back(v);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
