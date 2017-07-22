/*

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> average;
        
        queue<TreeNode*> q;
        if(root==NULL)
            return average;
        q.push(root);
        while(!q.empty())
        {
            double nodecount=q.size();
            double sum=0;
            double count=nodecount;
            while(nodecount>0)
            {
                TreeNode* t=q.front();
                sum=sum+t->val;
                q.pop();
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
                --nodecount;
            }
            average.push_back(sum/count);
        }
        return average;
    }
};
