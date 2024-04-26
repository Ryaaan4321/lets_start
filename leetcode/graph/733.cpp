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
    vector<vector<int>> floodFill(vector<vector<int>> &grid, int sr, int sc, int color)
    {
        int n = grid.size();
        int m = grid[0].size();
        int icolor = grid[sr][sc];
        queue<pair<int, int>> q;
        vector<vector<int>> vis = grid;
        vis[sr][sc] = icolor;
        q.push({sr, sc});

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++)
            {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if (isvalid(newrow, newcol, n, m) && grid[newrow][newcol] == icolor && vis[newrow][newcol] != color)
                {
                    vis[newrow][newcol] = color;
                    q.push({newrow, newcol});
                }
            }
        }
        return vis;
    }

    void fuc(int i, int j, int n, int m, int color, int newcolo, vector<vector<int>> grid)
    {
        grid[i][j] = color;
        if (isvalid(i + 1, j, n, m))
        {
            fuc(i + 1, j, n, m, color, newcolo, grid);
        }
        if (isvalid(i - 1, j, n, m))
        {
            fuc(i - 1, j, n, m, color, newcolo, grid);
        }
        if (isvalid(i, j + 1, n, m))
        {
            fuc(i, j + 1, n, m, color, newcolo, grid);
        }
        if (isvalid(i, j - 1, n, m))
        {
            fuc(i, j - 1, n, m, color, newcolo, grid);
        }
    }
    vector<vector<int>> floodFill2(vector<vector<int>> &grid, int sr, int sc, int newcolor)
    {
        int n = grid.size();
        int m = grid[0].size();

        int color = grid[sr][sc];
        if (color != newcolor)
        {
            fuc(sr, sc, n, m, color, newcolor, grid);
        }
        return grid;
    }
};