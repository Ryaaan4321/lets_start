#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int N = vals.size();
        int res = INT_MIN;
        vector<vector<int>> adj(vals.size(), vector<int>());
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(vals[v]);
            adj[v].push_back(vals[u]);
        }
        for (auto &e : adj) {
            sort(e.begin(), e.end(), greater<int>());
        }
        for (int i = 0; i < vals.size(); i++) {
            int c = 0;
            int tmp = k;
            for (auto K : adj[i]) {
                if (K > 0 && tmp > 0) {
                    c += K;
                    tmp--;

                } else {
                    break;
                }
            }
            res = max(res, c + vals[i]);
        }
        return res;
    }
};