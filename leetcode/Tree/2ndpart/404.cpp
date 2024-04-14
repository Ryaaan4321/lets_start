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
    void dfs(TreeNode *root, bool is_flag, int &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right && is_flag)
        {
            ans += root->val;
        }
        dfs(root->left, true, ans);
        dfs(root->right, false, ans);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        queue<pair<TreeNode *, bool>> q;
        q.push({root, false});
        int ans = 0;
        while (!q.empty())
        {
            auto temp = q.front();
            TreeNode *node = temp.first;
            bool is_flag = temp.second;
            q.pop();

            if (is_flag && !node->left && !node->right)
            {
                ans += node->val;
            }
            if (node->left)
            {
                q.push({node->left, true});
            }
            if (node->right)
            {
                q.push({node->right, false});
            }

            /* code */
        }
        return ans;
    }
};