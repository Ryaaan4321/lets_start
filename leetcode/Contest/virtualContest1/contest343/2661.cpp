#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check1(int col, vector<vector<int>>& mat, vector<vector<int>>& vis) {
        int n = mat.size();
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            if (vis[row][col]) {
                cnt++;
            }
        }
        return cnt == n;
    }
    bool check2(int row, vector<vector<int>>& mat, vector<vector<int>>& vis) {
        int m = mat[0].size();
        int cnt = 0;
        for (int col = 0; col < m; col++) {
            if (vis[row][col]) {
                cnt++;
            }
        }
        return cnt == m; 
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int mn = INT_MAX;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                position[mat[i][j]] = {i, j};
            }
        }
        for (int idx = 0; idx < arr.size(); idx++) {
            int val = arr[idx];
            auto [i, j] = position[val];
            vis[i][j] = 1; 
            if (check1(j, mat, vis) || check2(i, mat, vis)) {
                return idx; 
            }
        }
        return -1; 
    }
};
