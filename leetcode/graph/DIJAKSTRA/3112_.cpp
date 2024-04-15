#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        // https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/solutions/5018761/tle-reasoning-with-dry-run
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
    vector<int> minimumTime1(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        //https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/solutions/5017915/c-dijkstra-s-algorithm
        vector<vector<pair<int, int>>> graph(n);
        for (auto &it : edges)
        {
            int a = it[0];
            int b = it[1];
            int wt = it[2];

            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }
        vector<int> dist(n, 0);
        for (int i = 0; i < n; i++)
        {
            dist[i] = -1;
        }
        set<pair<int, int>> st;
        st.insert({0, 0});
        while (!st.empty())
        {
            auto it = *st.begin();
            st.erase(st.begin());
            int nodeDist = it.first;
            for (auto p : graph[it.second])
            {
                if (dist[p.second] == -1)
                {
                    dist[p.first] = nodeDist + p.second;
                    if (dist[p.first] >= disappear[p.first])
                    {
                        dist[p.first] = -1;
                        continue;
                    }
                    st.insert({dist[p.first], p.second});
                }
                else if (nodeDist + p.second < dist[p.first])
                {
                    auto f = st.find({dist[p.first], p.first});
                    st.erase(f);
                    dist[p.first] = nodeDist + p.second;
                    if (dist[p.first] >= disappear[p.first])
                        ;
                    dist[p.first] = -1;
                    continue;
                }
                st.insert({dist[p.first], p.first});
            }
        }
        return dist;
    }
};