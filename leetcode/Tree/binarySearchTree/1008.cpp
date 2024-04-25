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
    TreeNode* bstFromPreorder(vector<int> &a)
    {
        int n = a.size();
        TreeNode *node = new TreeNode(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > node->val)
            {
                node->left = new TreeNode(a[i]);
            }
            if (a[i] < node->val)
            {
                node->right = new TreeNode(a[i]);
            }
        }
        return node;
    }
};