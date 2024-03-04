#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDiffrence(TreeNode *node, int maxval, int minval)
    {
        if (node == nullptr)
            return maxval - minval;

        maxval = max(maxval, node->val);
        minval = min(minval, node->val);

        int maxLeftDiff = maxDiffrence(node->left, maxval, minval);
        int maxRightDiff = maxDiffrence(node->right, maxval, minval);

        return max(maxLeftDiff, maxRightDiff);
    }
    int maxAncestorDiff(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        return maxDiffrence(node, node->val, node->val);
    }
};
