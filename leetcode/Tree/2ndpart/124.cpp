#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    int dfs(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = max(0, dfs(root->left, maxi));
        /*if we get the  negative value then in 
        that case taking 0 to not get the negative value that degrades to our final answer*/
        int right = max(0, dfs(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = -1e9;
        dfs(root, maxi);
        return maxi;
    }
     int maxPathSum(TreeNode *root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int umx=0;
        while(!q.empty()){
           int sz=q.size();
           int sm=0;
           while (sz--)
           {
             auto node=q.front();
             q.pop();
             int lsm=0;int rsm=0;
             if(node->left){
                lsm=max(0,node->left->val);
                q.push(node->left);
             }
             if(node->right){
                rsm=max(0,node->right->val);
                q.push(node->right);
             }
             sm=max(sm,lsm+rsm+node->val);
           }
           umx=max(sm,umx);
        }
        return umx;
    }
};