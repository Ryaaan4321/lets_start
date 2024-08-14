#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkForCycle(it, node, vis, adj))
            return true;
        } else if (it != parent)
          return true;
      }

      return false;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
    }
};