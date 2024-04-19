#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
;

class Solution
{
public:
    int n;
    int m;
    bool check(int i, int j)
    {
        return (0 < i) && (i < n) && (0 < j) && (j < m);
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (!check(i, j))
        {
            return;
        }
        if (grid[i][j] == '1')
        {
            grid[i][j] = '2';
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
        }
    };
    int numIslands(vector<vector<char>> &grid)
    {
        
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};