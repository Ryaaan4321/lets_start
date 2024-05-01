#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return (i>=0) && (j>=0) && (i < n) && (j < m);
    }
    void dfs(int row, int col, int row0, int col0, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> v)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        v.push_back({row0-row,col0-col});
        int delrow[4] = {-1, 0, +1, 0};
        int delcol[4] = {0, -1, 0, +1};
        for (int i = 0; i < 4; i++)
        {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if (isvalid(newrow, newcol, n, m) && grid[newrow][newcol]  &&!vis[newrow][newcol] && grid[newrow][newcol] == 1)
            {
                dfs(newrow, newcol, row0, col0, grid, vis, v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> s;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    vector<pair<int, int>> p;
                    dfs(i, j, i, j, grid, vis, p);
                    s.insert(p);
                }
            }
        }
        return s.size();
    }
};