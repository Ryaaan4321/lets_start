#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : roads) {
            int node = it[0];
            int adjnode = it[1];
            int wt = it[2];
            adj[node].push_back({adjnode, wt});
            adj[adjnode].push_back({node, wt});
        }
        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(1);
        vis[1] = 1;
        int mn = INT_MAX;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                mn = min(mn, it.second);
                if (!vis[it.first]) {
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return mn;
    }
};