#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dfs(adj, v, visited, st);
            }
        }
        st.push(u);
    };
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited;
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited, st);
            }
        }
        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
          
        }
        return res;
    }
};