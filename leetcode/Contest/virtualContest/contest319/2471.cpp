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
        left = right = nullptr;
    }
};
 class Solution
{
public:
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int _le=0;
        int _ri=0;
        int cnt=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(root->left){
                _le=root->val;
                q.push(root->left);
            }
            if(root->right){
                _ri=root->val;
                q.push(root->right);
            }
            if(_le>_ri){
                cnt++;
            }
        }
        _le=0;
        _ri=0;
        return cnt;
    }
};