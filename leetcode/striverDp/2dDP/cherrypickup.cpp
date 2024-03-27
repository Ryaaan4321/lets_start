#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    int n;
    int m;
    int solve(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        {
            return -1e9;
        }
        if (i == n - 1)
        {
            if (j1 == j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }
        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int ans;
                if (j1 == j2)
                {
                    ans = grid[i][j1] + solve(i + 1, j1 + di, j2 + dj, grid, dp);
                }
                else
                {
                    ans = grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + di, j2 + dj, grid, dp);
                }
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        n = grid.size();
        m = grid[0].size();
        return solve(0, 0, m - 1, grid, dp);
    }
};