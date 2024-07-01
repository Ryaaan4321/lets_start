#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


// check the leetcode for the more clarity wel u dont get the clarity 
class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> sz;
    int cnt;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1);
        cnt = n;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
        cnt--;
    }
    void unionbysize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
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
    bool issingle() { return cnt == 1; }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);
        auto lamda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };
        int c=0;
        sort(edges.begin(), edges.end(), lamda);
        for (auto &it : edges) {
            int _t = it[0];
            int u = it[1];
            int v = it[2];

            if (_t == 3) {
                bool f = 0;
                if (alice.findParent(u) != alice.findParent(v)) {
                    alice.unionByRank(u, v);
                    f = 1;
                } else if (bob.findParent(u) != bob.findParent(v)) {
                    bob.unionByRank(u, v);
                    f = 1;
                }
                if (f == 1) {
                    c++;
                }
            } else if (_t == 2) {
                if (bob.findParent(u) != bob.findParent(v)) {
                    bob.unionByRank(u, v);
                    c++;
                }
            } else {
                if (alice.findParent(u) != alice.findParent(v)) {
                    alice.unionByRank(u, v);
                    c++;
                }
            }
        }
        if (alice.issingle() && bob.issingle()) {
            return edges.size() - c;
        }
        return -1;
    }
};