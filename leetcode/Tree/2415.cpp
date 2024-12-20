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
    void fuc(TreeNode *l, TreeNode *r, int lev)
    {
        if (!l || !r)
            return;
        if (lev & 1)
        {
            swap(l->val, r->val);
        }
        lev++;
        fuc(l->left, r->right, lev);
        fuc(l->right, r->left, lev);
    }
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool f = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<TreeNode *> arr(sz);
            for (int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                if (f)
                {
                    arr[i] = node;
                    if (i >= sz / 2)
                    {
                        swap(arr[i]->val, arr[sz - 1 - i]->val);
                    }
                }
            }
            f = !f;
        }
        return root;
    }
};
;