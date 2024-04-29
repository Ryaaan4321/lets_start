#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return (i < 0) || (i >= n) || (j < 0) || (j >= m);
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (isvalid(i, j, n, m) || grid[i][j] != 1)
        {
            return;
        }
        grid[i][j] = 2;
        dfs(i - 1, j, n, m, grid);
        dfs(i + 1, j, n, m, grid);
        dfs(i, j + 1, n, m, grid);
        dfs(i, j - 1, n, m, grid);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int j = 0; j < m; j++)
        {
            dfs(0, j, n, m, grid);
            dfs(n - 1, j, n, m, grid);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, n, m, grid);
            dfs(i, m - 1, n, m, grid);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
                if(grid[i][j]==2){
                    grid[i][j]=0;
                }
            }
        }
        return cnt;
    }
};