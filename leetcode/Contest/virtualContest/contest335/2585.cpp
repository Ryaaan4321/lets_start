#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

const int mod = 1e9 + 7;
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<vector<int>>> dp(
            1001, vector<vector<int>>(51, vector<int>(51, -1)));
        return fucc(target, types, 0, 0, dp);
    }
    int fucc(int target, vector<vector<int>>& grid, int i, int j,
             vector<vector<vector<int>>>& dp) {
        if (target < 0 || i == grid.size() || j > grid[i][0])
            return 0;
        if (target == 0) {
            return 1;
        }
        if (dp[target][i][j] != -1)
            return dp[target][i][j];

        int ways = 0;
        ways += fucc(target - grid[i][1], grid, i, j + 1, dp);
        ways += fucc(target, grid, i + 1, 0, dp);
        ways %= mod;
        dp[target][i][j] = ways;
        return ways;
    }
};