#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if (i == grid.size() - 1 && j == grid.size() - 1)
        {
            return grid[i][j];
        }
        if (i >= grid.size() || j >= grid[0].size())
        {
            return 1e5;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = grid[i][j] + solve(grid, i + 1, j, dp);
        int down = grid[i][j] + solve(grid, i, j + 1, dp);

        return dp[i][j] = min(right, down);
    };
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, 0, 0, dp);
    }
};