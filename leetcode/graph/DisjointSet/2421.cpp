#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findparent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findparent(parent[x]);
    }
    void unionbyrank(int x, int y) {
        int pa_x = findparent(x);
        int pa_y = findparent(y);
        if (pa_x == pa_y) {
            return;
        }
        if (rank[pa_x] > rank[pa_y]) {
            parent[pa_y] = pa_x;
        } else if (rank[pa_y] > rank[pa_x]) {
            parent[pa_x] = pa_y;
        } else {
            parent[pa_x] = pa_y;
            rank[pa_y]++;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DisjointSet ds(n);
        unordered_map<int, vector<int>> adj;
        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, vector<int>> valtonode;
        for (int i = 0; i < n; i++) {
            int value = vals[i];
            valtonode[value].push_back(i);
        }
        int result = n;
        vector<bool> isactive(n, 0);
        for (auto& it : valtonode) {
            vector<int> nodes = it.second;
            for (int& u : nodes) {
                for (int& v : adj[u]) {
                    if (isactive[v]) {
                        ds.unionbyrank(u, v);
                    }
                }
                isactive[u] = true;
            }
            vector<int> tumhare_parent;
            for (int& u : nodes) {
                int parent_kaun_hai = ds.findparent(u);
                tumhare_parent.push_back(parent_kaun_hai);
            }
            sort(begin(tumhare_parent), end(tumhare_parent));
            int sz = tumhare_parent.size();
            for (int j = 0; j < sz; j++) {
                long long cnt = 0;
                int cur_parent = tumhare_parent[j];
                while (j < sz && tumhare_parent[j] == cur_parent) {
                    cnt++;
                    j++;
                }
                j--;
                int formula = (cnt * (cnt - 1) / 2);
                result += formula;
            }
        }
        return result;
    }
};