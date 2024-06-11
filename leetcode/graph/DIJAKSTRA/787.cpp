#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& grid, int src, int dst,
                          int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        
        pq.push({0, {src, 0}});
        vector<pair<int, int>> adj[n];
        for (auto it : grid) {
            int u = it[0];
            int v = it[1];
            int co = it[2];
            adj[u].push_back({v, co});
        }
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        while (!pq.empty()) {
            auto tmp = pq.top();
            int s = tmp.first;
            int node = tmp.second.first;
            int price = tmp.second.second;
            pq.pop();
            if(s>k){
                continue;
            }

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int adjprice = it.second;
                if (adjprice + price < dist[adjnode]) {
                    dist[adjnode] = price + adjprice;
                    pq.push({s + 1, {adjnode,price + adjprice }});
                }
            }
        }
        return (dist[dst] !=INT_MAX ? dist[dst] : -1);
    }
   int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> distance(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int> &vec : flights)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back(make_pair(v, cost));
        }

        queue<pair<int, int>> que;
        que.push({src, 0});

        distance[src] = 0;
        int steps = 0;

        while (!que.empty() && steps <= k)
        {
            int N = que.size();
            while (N--)
            {
                int u = que.front().first;
                int d = que.front().second;

                que.pop();

                for (pair<int, int> &P : adj[u])
                {
                    int v = P.first;
                    int cost = P.second;

                    if (distance[v] > d + cost)
                    {
                        distance[v] = d + cost;
                        que.push({v, d + cost});
                    }
                }
            }
            steps++;

            /* code */
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};