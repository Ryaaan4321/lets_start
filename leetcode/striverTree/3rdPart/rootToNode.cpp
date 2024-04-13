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
    bool search(TreeNode *root, TreeNode *node, vector<int> &ans)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root == node)
        {
            return 1;
        }
        return search(root->left, node, ans) || search(root->right, node, ans);
    }
    vector<int> allRootToLeaf(TreeNode *root, TreeNode *p)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        search(root, p, ans);
        return ans;
    }
};