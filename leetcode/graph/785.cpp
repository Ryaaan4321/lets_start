#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool dfs(int node, int paint, vector<int> &color, vector<vector<int>>& grid) {
        color[node] = paint;
        for (auto& adjNode : grid[node]) {
            if (color[adjNode] == color[node]) {
                return 0;
            } else if (color[adjNode] == -1) {
                if (dfs(adjNode, 1 - paint, color, grid) == 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& grid) {
        int v = grid.size();
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, grid) == false) {
                    return 0;
                }
            }
        }
        return 1;
    }
};