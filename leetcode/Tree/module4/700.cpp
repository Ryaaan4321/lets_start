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
    TreeNode *searchBST(TreeNode *root, int target)
    {
        if (!root)
        {
            return nullptr;
        }
        if (root->val == target)
        {
            return root;
        }
        TreeNode *left = searchBST(root->left, target);
        TreeNode *right = searchBST(root->right, target);

        if (left == nullptr && right == nullptr)
        {
            return NULL;
        }
        return left != nullptr ? left : right;
    }
    // int min=INT_MAX
};