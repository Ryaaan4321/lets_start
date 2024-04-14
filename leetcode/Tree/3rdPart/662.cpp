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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        int ans = 0;
        while (!que.empty())
        {
            auto temp = que.front();
            int sz = que.size();
            int first, last;
            int min = temp.second;

            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = temp.first;
                int curr_min = temp.second - min;
                que.pop();

                if (i == 0)
                {
                    first = curr_min;
                }
                if (i == sz - 1)
                {
                    last = curr_min;
                }
                if (node->left)
                {
                    que.push({node->left, curr_min * 2 + 1});
                }
                if (node->right)
                {
                    que.push({node->right, curr_min * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);

            /* code */
        }
        return ans;
    }
};