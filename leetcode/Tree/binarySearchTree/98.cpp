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
    bool check(TreeNode *root)
    {
        /*implemented it to myself bt this code only passed the
        half of the  testcases;
        */
        queue<TreeNode *> q;
        q.push(root);
        if (root == NULL)
        {
            return 0;
        }
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && node->right)
            {
                if (node->left->val < node->right->val)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        return 0;
    }
    bool isValidBST(TreeNode *root, long min_val, long max_val)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val <= min_val || root->val >= max_val)
        {
            return false;
        }
        return isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val);
    }

    bool isValidBST(TreeNode *root)
    {
        return check(root);
    }
};