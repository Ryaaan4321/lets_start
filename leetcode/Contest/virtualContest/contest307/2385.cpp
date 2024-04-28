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
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        if (parent != -1)
        {
            adj[node->val].push_back(parent);
        }
        if (node->left)
        {
            adj[node->val].push_back(node->left->val);
        }
        if (node->right)
        {
            adj[node->val].push_back(node->right->val);
        }
        makeGraph(adj, node->val, node->left);
        makeGraph(adj, node->val, node->right);
    };
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);
        queue<int> q;
        unordered_set<int> vis;
        vis.insert(start);
        int min = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int curr = q.front();
                q.pop();
                for (int &adjacent : adj[curr])
                {
                    if (vis.find(adjacent) == vis.end())
                    {
                        q.push(adjacent);
                        vis.insert(adjacent);
                    }
                }
            }
            min++;
        }
        return min - 1;
    }
};