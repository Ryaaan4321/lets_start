#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int visit = 0;
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &cant_visit)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[node] && !cant_visit[node])
            {
                visit++;
                dfs(it, adj, vis, cant_visit);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> cant_visit(n + 1, 0), visited(n + 1);
        for (int it : restricted)
        {
            cant_visit[it] = 1;
        }
        visit = 1;
        dfs(0, adj, visited, cant_visit);
        return visit;
    }
};
