#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Disjointset {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> sz;
    Disjointset(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        sz.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int findparent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionbyrank(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
    void unionbysz(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (sz[ulp_u] > sz[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (sz[ulp_v] > sz[ulp_u]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            sz[ulp_u] += sz[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        Disjointset ds(n);
        int cnt = 0;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if (ds.findparent(u) == ds.findparent(v)) {
                cnt++;
            } else {
                ds.unionbyrank(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findparent(i) == i) {
                cntC++;
            }
        }
        int ans = cntC - 1;
        if (cnt >= ans) {
            return ans;
        } else {
            return -1;
        }
    }
};