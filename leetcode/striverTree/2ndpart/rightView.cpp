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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (1)
        {
            int sz = q.size();
            if (sz == 0)
            {
                return ans;
            }
            vector<int> data;
            while (sz--)
            {
                TreeNode *temp = q.front();
                q.pop();
                data.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(data.back());
        }
        return ans;
    }
    void dfs(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }
        if (res.size() == level)
        {
            res.push_back(root->val);
        }
        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);
    };
    vector<int> rightSideView2(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }
        dfs(root, 0, ans);
        return ans;
    }
};