#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int n;
    int m;
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= n - 1 && j >= m - 1 && dp[i][j] == 1)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        int right = solve(i+1, j, grid);
        int down = solve(i, j+1 , grid);

        return dp[i][j] = right + down;
    };
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, obstacleGrid);
    }
};