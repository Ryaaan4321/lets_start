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
    int florr(TreeNode *root, int key)
    {
        int floor = -1;
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }
        if (root->val > key)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
        return floor;
    }
};