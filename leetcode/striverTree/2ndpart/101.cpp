#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;

    int val;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool fuc(TreeNode *left, TreeNode *right)
    {
        if (!left || !right)
        {
            return left == right;
        }
        if (left->val != right->val)
            return false;
        return fuc(left->left, right->right) && fuc(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return fuc(root, root);
    }
};