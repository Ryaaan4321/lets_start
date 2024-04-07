#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y)
    {
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        parent.resize(n);
        vector<int> cost(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            cost[i] = -1;
        }
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v)
            {
                Union(parent_u, parent_v);
                cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= w;
        }
        vector<int> result;
        for (auto &q : query)
        {
            int s = q[0];
            int t = q[1];

            int parent_s = find(s);
            int parent_t = find(t);
            if (s == t)
            {
                result.push_back(0);
            }
            else if (parent_s != parent_t)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(cost[parent[s]]);
            }
        }
        return result;
    }
};