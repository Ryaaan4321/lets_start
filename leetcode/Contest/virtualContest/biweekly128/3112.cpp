#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    // https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/solutions/5018761/tle-reasoning-with-dry-run
    // https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/solutions/5017915/c-dijkstra-s-algorithm
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> graph[n + 1];
        for (auto e : edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(n + 1, INT_MAX);
        vector<int> time(n + 1, 0);
        pq.push({0, 0});
        dist[0] = 0;
        vector<bool> vis(n, 0);
        while (!pq.empty())
        {
            auto temp = pq.top();
            int u = temp.first;
            int v = temp.second;
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = true;

            if (time[u] < disappear[u])
            {
                for (auto it : graph[u])
                {
                    int v = it.first;
                    int weight = it.second;
                    if ((dist[v] > dist[u] + weight) && (time[u] + weight < disappear[u]))
                    {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                        time[v] = time[u] + weight;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (dist[i] == INT_MAX)
                {
                    ans[i] = -1;
                }
                else
                {

                    ans[i] = dist[i];
                }
            }
        }
        return ans;
    }
};