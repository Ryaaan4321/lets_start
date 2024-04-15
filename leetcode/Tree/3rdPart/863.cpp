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
    void parent_mark(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map, TreeNode *target)
    {
        if (!root)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr_node = q.front();
            q.pop();
            if (curr_node->left)
            {
                q.push(curr_node->left);
                parent_map[curr_node->left] = curr_node;
            }
            if (curr_node->right)
            {
                q.push(curr_node->right);
                parent_map[curr_node->right] = curr_node;
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        queue<TreeNode *> q;
        unordered_map<TreeNode *, TreeNode *> parent_map;
        parent_mark(root, parent_map, target);
        unordered_map<TreeNode *, bool> visited;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            if (curr_level == k)
            {
                break;
            }
            curr_level++;

            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr_node = q.front();
                q.pop();

                if (curr_node->left && !visited[curr_node->left])
                {
                    q.push(curr_node->left);
                    visited[curr_node->left] = true;
                }
                if (curr_node->right && !visited[curr_node->right])
                {
                    q.push(curr_node->right);
                    visited[curr_node->right] = true;
                }
                if (parent_map[curr_node] && !visited[parent_map[curr_node]])
                {
                    q.push(parent_map[curr_node]);
                    visited[parent_map[curr_node]] = true;
                }
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            TreeNode *curr_node = q.front();
            q.pop();
            res.push_back(curr_node->val);
        }
        return res;
    }
};