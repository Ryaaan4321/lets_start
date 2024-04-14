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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return (p == q);
        }
        bool left = 0;
        bool right = 0;
        if (p->val == q->val)
        {

            left = isSameTree(p->left, q->left);
        }
        if (p->val == q->val)
        {

            right = isSameTree(p->right, q->right);
        }
        return left && right;
    }
};