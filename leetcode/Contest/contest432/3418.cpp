#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[501][501][3];
    bool vis[501][501][3];

    long long fucc(int i, int j, int k, vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        if (i >= n || j >= m) return INT_MIN;
        if (i == n - 1 && j == m - 1) {
            if (a[i][j] < 0 && k > 0) return 0;
            return a[i][j];
        }
        if (vis[i][j][k]) {
            return dp[i][j][k];
        }
        long long t1 = INT_MIN, t2 = INT_MIN;
        t1 = a[i][j] + fucc(i + 1, j, k, a);
        if (a[i][j] < 0 && k > 0) {
            t1 = max(t1, fucc(i + 1, j, k - 1, a));
        }
        t2 = a[i][j] + fucc(i, j + 1, k, a);
        if (a[i][j] < 0 && k > 0) {
            t2 = max(t2, fucc(i, j + 1, k - 1, a));
        }
        vis[i][j][k] = 1;
        return dp[i][j][k] = max(t1, t2);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        return fucc(0, 0, 2, coins);
    }
};
