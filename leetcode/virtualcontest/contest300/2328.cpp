#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
constexpr long long modVal = 1000000007;

class Solution
{
    int n, m;
    vector<vector<int>> grid;
    vector<vector<long long>> dp;
    int dfs(int i, int j)
    {

        if (dp[j][i])
            return dp[j][i];

        int currCell = grid[j][i];
        long long subRes = 1;
        
        if (i < n && currCell < grid[j][i + 1])
            subRes += dfs(i + 1, j);
      
        if (j < m && currCell < grid[j + 1][i])
            subRes += dfs(i, j + 1);
      
        if (i && currCell < grid[j][i - 1])
            subRes += dfs(i - 1, j);
        
        if (j && currCell < grid[j - 1][i])
            subRes += dfs(i, j - 1);
        return dp[j][i] = subRes % modVal;
    }

public:
    int countPaths(vector<vector<int>> &tmp)
    {

        long long res = 0;

        swap(tmp, grid);
        n = grid[0].size(), m = grid.size();
        vector<vector<long long>> tmpDp(m--, vector<long long>(n--, 0));
        swap(tmpDp, dp);

        for (int y = 0; y <= m; y++)
        {
            for (int x = 0; x <= n; x++)
            {

                if (!dp[y][x])
                {
                    dp[y][x] = dfs(x, y);
                }
                res += dp[y][x];
            }
        }
        return res % modVal;
    }
};