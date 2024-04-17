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
    string ans = "";
    void dfs(TreeNode *root, string curr_ans)
    {
        if (!root)
        {
            return;
        }
        curr_ans = char(root->val + 'a') + curr_ans;
        if (!root->left && !root->right)
        {
            if (ans == "" || ans > curr_ans)
            {
                ans = curr_ans;
            }
            return;
        }
        dfs(root->left, curr_ans);
        dfs(root->right, curr_ans);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, "");
        return ans;
    }
    string smallestFromLeaf2(TreeNode *root)
    {
        queue<pair<TreeNode *, string>> q;
        q.push({root, string(1, char(root->val + 'a'))});
        string result = "";
        while (!q.empty())
        {
            auto temp = q.front();
            TreeNode *node = temp.first;
            string curr = temp.second;

            if (!node->left && !node->right)
            {
                if (result == "" || result > curr)
                {
                    result = curr;
                }
            }
            if (node->left)
            {
                q.push({node->left, char(node->left->val + 'a') + curr});
            }
            if (node->right)
            {
                q.push({node->right, char(node->right->val + 'a') + curr});
            }
            /* code */
        }
        return result;
    };
};
