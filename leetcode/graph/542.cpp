#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        while (!q.empty())
        {
            pair<int, pair<int, int>> node = q.front();
            int step = node.first;
            int row = node.second.first;
            int col = node.second.second;
            q.pop();
            dis[row][col] = step;

            for (int i = 0; i < 4; i++)
            {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if (isvalid(newrow, newcol, n, m) && !vis[newrow][newcol])
                {
                    vis[newrow][newcol] = 1;
                    q.push({step + 1, {newrow, newcol}});
                }
            }
        }
        return dis;
    }
};