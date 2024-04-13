#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int n;
    void dfs(vector<int> &edges, int startnode, vector<int> &dist, vector<bool> &visited)
    {
        visited[startnode] = true;

        int v = edges[startnode];

        if (v != -1 && !visited[v])
        {
            visited[v] = true;
            dist[v] = 1 + dist[startnode];
            dfs(edges, v, dist, visited);
        }
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int minDistanceNode = -1;
        int minDistanceTillNow = INT_MAX;

        for (int i = 0; i < n; ++i)
        {

            int maxD = max(dist1[i], dist2[i]);
            if (minDistanceTillNow > maxD)
            {
                maxD = minDistanceTillNow;
                minDistanceNode = i;
            }
        }
        return minDistanceNode;
    }

private:
    int n;
    void bfs(vector<int> &edges, int startNode, vector<int> &dist_node)
    {
        n = edges.size();
        queue<int> q;
        q.push(startNode);
        dist_node[startNode] = 0;
        vector<bool> visited(n, false);

        visited[startNode] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            int v = edges[u];

            if (v != -1 && !visited[v])
            {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minDistNode = -1;
        int minDistTIllNow = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int maxD = max(dist1[i], dist2[i]);
            if (minDistTIllNow > maxD)
            {
                maxD = minDistTIllNow;
                minDistNode = i;
            }
        }
        return minDistNode;
    }
};