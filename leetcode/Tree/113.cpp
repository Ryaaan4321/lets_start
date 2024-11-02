#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> lsm;
            vector<int> rsm;
            while (sz--)
            {
                int sm = 0;
                auto node = q.front();
                q.pop();
                sm += node->val;
                if (sm == targetSum)
                {
                    ans.push_back(lsm);
                    ans.push_back(rsm);
                }
                if (node->left->val < targetSum)
                {
                    sm += node->left->val;
                    lsm.push_back(node->left->val);
                }
                if (node->right->val < targetSum)
                {
                    sm += node->right->val;
                    rsm.push_back(node->right->val);
                }
            }
        }
        return ans;
    }
};