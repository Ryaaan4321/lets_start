#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    void fucc(int node, int& nodecount, int& edegecount,
              map<int, vector<int>> graph, vector<bool>& vis) {
        vis[node] = true;
        nodecount += 1;
        edegecount += graph[node].size();
        for (auto nei : graph[node]) {
            if (!vis[nei]) {
                fucc(nei, nodecount, edegecount, graph, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        vector<bool> vis(n);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int cnt = 0;
        for (int node = 0; node < n; node++) {
            int nodecount = 0;
            int edgecount = 0;
            if (!vis[node]) {
                fucc(node, nodecount, edgecount, graph, vis);
                if (nodecount * (nodecount - 1) == edgecount)cnt++;
            }
        }
        return cnt;
    }
};