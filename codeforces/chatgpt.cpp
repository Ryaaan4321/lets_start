#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

vector<pair<int, int>> adj[100005];
int vis[100005];

signed main()
{
    int num;
    cin >> num;
    int mx = 100004;
    for (int i = 0; i < num; i++)
    {
        int b;
        cin >> b;
        mx = max(mx, b);
    }
    int edge;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int src, destination;
    cin >> src >> destination;
    vector<int> dist(mx, 1e9);
    vector<int> par(mx, 0);
    for (int i = 0; i <= mx; i++)
    {
        par[i] = i;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (pq.size() > 0)
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto &k : adj[node])
        {
            int adjnode = k.first;
            int adjwt = k.second;
            if (dist[adjnode] > adjwt + dis)
            {
                dist[adjnode] = adjwt + dis;
                par[adjnode] = node;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    // Debugging print statements
    cout << "Distance to destination: " << dist[destination] << endl;

    if (dist[destination] != 1e9)
    {
        vector<int> ans;
        int i = destination;
        while (par[i] != i)
        {
            i = par[i];
            ans.push_back(i);
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << destination << endl;
    }
    else
    {
        cout << "No path from source to destination." << endl;
    }

    return 0;
}
