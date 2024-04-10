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
    int result=INT_MIN;
    int dfs(TreeNode *root, int result)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right) ;
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        dfs(root,result);
        return result;
    }
};