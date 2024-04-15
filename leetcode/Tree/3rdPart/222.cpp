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
    int findLeftTreeHeight(TreeNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int findRightTreeHeight(TreeNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = findLeftTreeHeight(root);
        int right = findRightTreeHeight(root);

        if (left == right)
        {
            return (1 << left) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int countNodes1(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else if (root->right == NULL)
        {
            return countNodes(root->left) + 1;
        }
        else if (root->left == NULL)
        {
            return countNodes(root->right) + 1;
        }
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};