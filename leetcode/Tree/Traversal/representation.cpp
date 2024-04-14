#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    int solve(TreeNode *root)
    {
        TreeNode *a = new TreeNode(3);
        a->left = new TreeNode(4);
        a->right = new TreeNode(4);

        TreeNode *aa = new TreeNode(5);
        a->right->right = aa;
        return a->data;
    }
};
