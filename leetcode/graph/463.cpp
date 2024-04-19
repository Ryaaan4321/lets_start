#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
;

class Solution
{
public:
    int perimeter;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool check(int i, int j, int n, int m)
    {
        return (0 <= i) && (i < n) && (0 <= j) && (j < m);
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid)
    {
        if (!check(i, j, n, m))
            ;
        {
            return;
        }
        if (grid[i][j] == '1')
        {
            grid[i][j] = '2';
            dfs(i + 1, j, n, m, grid);
            dfs(i - 1, j, n, m, grid);
            dfs(i, j + 1, n, m, grid);
            dfs(i, j - 1, n, m, grid);
        }
    };
    int bfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            for (auto &dir : directions)
            {
                int row = it.first + dir[0];
                int col = it.second + dir[1];

                if (check(row, col, n, m) || grid[row][col] == 0)
                {
                    perimeter++;
                }
                else if (grid[row][col] == -1)
                {
                    continue;
                }
                else
                {
                    q.push({row, col});
                    grid[row][col] = -1;
                }
            }
        }
        return perimeter;
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return cnt;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int res = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == 0)
                {
                    continue;
                }
                if (row > 0 && grid[row - 1][col] == '1')
                    cnt++;
                if (row < n && grid[row + 1][col] == '1')
                    cnt++;
                if (col > 0 && grid[row][col - 1] == '1')
                    cnt++;
                if (col < m && grid[row][col + 1] == '1')
                    cnt++;

                res += 4 - cnt;
            }
        }
        return res;
    }
};