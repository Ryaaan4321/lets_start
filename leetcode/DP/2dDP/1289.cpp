#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int dp[201][201];
    int fuc(int row, int col, vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (row == n - 1)
        {
            return grid[row][col];
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int ans = INT_MAX;
        for (int newcol = 0; newcol < n; newcol++)
        {
            if (newcol != col)
            {
                ans = min(ans, fuc(newcol, row + 1, grid));
            }
        }
        return dp[row][col] = ans + grid[row][col];
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int result = INT_MAX;

        for (int col = 0; col < n; col++)
        {
            result = min(result, fuc(0, col, grid));
        }
        return result;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, INT_MAX));

        for (int col = 0; col < n; col++)
        {
            // filling the last row becuase from herre we will start
            dp[n - 1][col] = grid[n - 1][col];
        }
        for (int row = n - 2; row >= 0; row--)
        {
            //now becuasse wee are done with the n-1th row so starting with the n-2 row
            for (int col = 0; col < n; col++)
            {// traversing over the column//
            
                int ans = INT_MAX;
                // loop to check if the newcol and the col are not the adjacent
                // if they re not adjancent than we will mover forward
                for (int newcol = 0; newcol < n; newcol++)
                {
                    if (col != newcol)
                    {
                        ans = min(ans, dp[row + 1][newcol]);
                    }
                }
                dp[row][col] = ans + grid[row][col];
            }
        }
        int result = 0;
        for (int col = 0; col < n; col++)
        {
            result = min(result, dp[0][col]);
        }
        return result;
    }
};