/*

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> vec;
        queue<TreeNode*> q;
        if(root==NULL)
            return vec;
        q.push(root);
        while(!q.empty())
        {
            int nodecount=q.size();
            int large=INT_MIN;
            while(nodecount>0)
            {
                TreeNode* temp=q.front();
                if(temp->val>large)
                    large=temp->val;
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                --nodecount;
            }
            vec.push_back(large);
        }
        return vec;
        
    }
};
