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
    int ceilValue(TreeNode *root, int key)
    {
        int ceil = -1;
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }
        if(root->val >key){
            root=root->right;

        }else{
            ceil=root->val;
            root=root->left;
        }
        return ceil;
    }
};