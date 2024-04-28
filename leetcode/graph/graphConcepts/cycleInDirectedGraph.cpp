#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool fuc(vector<int> adj[], int u, vector<bool> &vis, vector<bool> &inrecursion)
    {
        vis[u] = true;
        inrecursion[u] = true;

        for (auto &v : adj[u])
        {
            if (!vis[v] && fuc(adj, v, vis, inrecursion))
            {
                return 1;
            }
            else if (inrecursion[v] == 1)
            {
                return 1;
            }
        }
        inrecursion[u] = 0;
        return false;
    }
    bool isCyclic(vector<int> adj[], int V)
    {
        vector<bool> visited(V, 0);
        vector<bool> inrecurison(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && fuc(adj, i, visited, inrecurison))
            {
                return 1;
            }
        }
        return 0;
    }
};