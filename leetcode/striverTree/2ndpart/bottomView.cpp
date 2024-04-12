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
    vector<int> bottomView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;
        q.push({root, 0});

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int line = temp.second;

            if (mp.find(line) != mp.end())
            {
                mp[line] = node->val;
            }
            if (node->left)
            {
                q.push({node->left, line - 1});
            }
            if (node->right)
            {
                q.push({node->right, line + 1});
            }

            /* code */
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};