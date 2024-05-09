#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

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
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void unionbyrank(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_v == ulp_u)
            return;
        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
    void unionbysize(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_u == ulp_v)
            return;
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
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjointset ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ds.unionbyrank(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                cnt++;
            }
        }
        return cnt;
    }
};