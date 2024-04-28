#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> adj[], int u, vector<bool> vis, vector<int> &res)
    {
        if (vis[u] == 1)
        {
            return;
        }
        vis[u] = 1;
        res.push_back(u);
        for (auto &v : adj[u])
        {
            if (!vis[v])
            {
                dfs(adj, v, vis, res);
            }
        }
    }
    vector<int> dfsGraph(int V, vector<int> mp[])
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < V; i++)
        {
            for (auto v = mp[i].begin(); v != mp[i].end(); v++)
            {
                adj[i].push_back(*v);
            }
        }
        vector<int> result;
        vector<bool> vis(V, false);
        dfs(mp, 0, vis, result);
        return result;
    }
};