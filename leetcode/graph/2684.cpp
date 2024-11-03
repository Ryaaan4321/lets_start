#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int dr[3] = {-1, 0, 1};
    int dc[3] = {1, 1, 1};
    int dp[1001+3][1001+3];
    int n;
    int m;
    bool isvalid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    int fucc(int row, int col, vector<vector<int>>& grid) {
        int cnt = 0;
        m = grid[0].size();
        n = grid.size();
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        for (int i = 0; i < 3; i++) {
            int newr = row + dr[i];
            int newc = col + 1;
            if (isvalid(newr, newc, n, m, grid) &&
                grid[newr][newc] > grid[row][col]) {
                cnt = max(cnt, 1 + fucc(newr, newc, grid));
            }
        }
        return dp[row][col]=cnt;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid[0].size();
        n = grid.size();
        int res = 0;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++) {
            res = max(res, fucc(i, 0, grid));
        }
        return res;
    }
};


