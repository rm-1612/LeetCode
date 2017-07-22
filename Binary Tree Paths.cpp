/*

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

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

void print_paths(TreeNode* root,int path[],int pathlen,vector<string> &ans)
{
    if(root==NULL)
        return ;
    path[pathlen]=root->val;
    ++pathlen;
    if(root->left==NULL && root->right==NULL)
    {
        string str="";
        for(int i=0;i<pathlen;++i)
        {
            str=str+to_string(path[i]);
            if(i==pathlen-1)
                break;
            str=str+'-'+'>';
        }
        ans.push_back(str);
        return ;
    }
    print_paths(root->left,path,pathlen,ans);
    print_paths(root->right,path,pathlen,ans);
}
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        int pathlen=0;
        int path[100005];
        print_paths(root,path,pathlen,ans);
        return ans;
    }
};
