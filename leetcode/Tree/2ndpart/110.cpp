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
    int dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);

        return max(left, right) + 1;
    };
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return 1;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(dfs(root->left) - dfs(root->right)) <= 1;

        if (left && right && diff)
        {
            return 1;
        }
        return 0;
    }
};