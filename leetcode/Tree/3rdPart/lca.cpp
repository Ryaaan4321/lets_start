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
    TreeNode *lowestCommmonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommmonAncestor(root->left, p, q);
        TreeNode *right = lowestCommmonAncestor(root->right, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
    TreeNode *lowestCommmonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *lca = nullptr;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            bool isPChild = search(root, p);
            bool isQChild = search(root, q);

            if (isPChild && isQChild)
            {
                lca = node;
            }
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
            return lca;
            /* code */
        }
    }
    bool search(TreeNode *root, TreeNode *node)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root == node)
        {
            return 1;
        }
        return search(root->left, node) || search(root->right, node);
    }
};