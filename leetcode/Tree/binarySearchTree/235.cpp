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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int curr = root->val;
        if (curr < p->val && curr < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (curr > p->val && curr > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};