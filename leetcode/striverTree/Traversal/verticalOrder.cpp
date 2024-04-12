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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int vertical = temp.second.first;
            int level = temp.second.second;
            nodes[vertical][level].insert(node->val);
            if (node->left)
            {
                q.push({node->left, {vertical - 1, level + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {vertical   + 1, level + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};