#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool fuc(vector<int> adj[], vector<bool> vis, int u, int parent)
    {
        vis[u] = true;
        for (auto &v : adj[u])
        {
            if (parent == v)
            {
                continue;
            }
            if (!vis[v])
            {
                return 1;
            }
            if (fuc(adj, vis, 0, -1))
            {
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(vector<int> adj[], int V)
    {
        unordered_map<int, vector<int>> mp;
        vector<bool> vis;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && fuc(adj, vis, 0, -1))
            {
                return 1;
            }
        }
        return 0;
    }
    bool bfs(vector<int> adj[], vector<bool> &vis, int u, int parent)
    {
        queue<pair<int, int>> q;
        q.push({u, -1});
        vis[u] = 1;
        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();

            int src = node.first;
            int parent = node.second;

            for (auto &v : adj[src])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push({v, src});
                }
                else if (v != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle2(vector<int> adj[], int V)
    {
        vector<bool> vis(V, false);
        vector<int> res;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && bfs(adj, vis, 0, -1))
            {
                return 1;
            }
        }
        return 0;
    }
};