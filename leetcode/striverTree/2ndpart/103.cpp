#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;

        q.push(root);
        bool flag = 1;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> temp;

            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int idx = (flag) ? i : (sz - 1 - i);
                temp[idx] = node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;

        q.push(root);
        bool flag = 0;
        while (q.size())
        {
            int sz = q.size();
            vector<int> temp;

            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }

            if (flag == 0)
            {
                flag = 1;
                ans.push_back(temp);
            }
            else
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                flag = 0;
            }
        }
        return ans;
    }
};