#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{

    int m, n;

    int solve(vector<vector<int>> &grid, int row, int col_1, int col_2)
    {
        if (row >= m)
        {
            return 0;
        }

        int cherry = grid[row][col_1];
        if (col_1 != col_2)
        {
            cherry += grid[row][col_2];
        }
        int ans = 0;
        for (int i = -1; i <= 1; ++i) /*thats is represneting the location of our first robot*/
        {
            for (int j = -1; j <= 1; ++j) /* and becuase for each  movement of the ist
            robot we can place our 2nd robot
             so thats why using nested for loop to check if they can be placed here or not*/
            {
                int newRow = row + 1;
                int newcol_1 = col_1 + j;
                int newcol_2 = col_2 + j;

                if (newcol_1 >= 0 && newcol_1 < n && newcol_2 >= 0 && newcol_2 < n)
                {
                    ans = max(ans, solve(grid, newRow, newcol_1, newcol_2));
                }
            }
        }
        return cherry + ans;
    }
    int dp[71][71][71];

    int solve2(vector<vector<int>> &grid, int row, int col_1, int col_2)
    {
        if (row >= m)
        {
            return 0; // no cherry as we are out of bounds
        }
        if (dp[row][col_1][col_2] != -1)
        {
            return dp[row][col_1][col_2];
        }
        int cherry = grid[row][col_1];
        if (col_1 != col_2)
        {
            cherry += grid[row][col_2];
        }
        int ans = 0;
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                int newRow = row + 1;
                int newCol_1 = col_1 + i;
                int newCol_2 = col_2 + j;

                if (newRow < m && newCol_1 >= 0 && newCol_1 < n && newCol_2 >= 0 && newCol_2 < n)
                {
                    ans = max(ans, solve2(grid, newRow, newCol_1, newCol_2));
                }
            }
        }
        return dp[row][col_1][col_2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        m = grid.size();
        if (m == 0)
            return 0; // Empty grid
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve2(grid, 0, 0, n - 1);
    }
    /* --------------------------------- BOTTOM UP 3D DP  ---------------------------------------------*/
    int cherryPickup2(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int t[71][71][71];
        t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1];

        for (int row = 1; row < m; row++)
        {
            for (int c1 = 0; c1 <= min(n - 1, row); c1++)
            {
                for (int c2 = max(0, n - row - 1); c2 < n; c2++)
                {
                    int prevRowMax = 0;
                    for (int prevCol1 = max(0, c1 - 1); prevCol1 <= min(n - 1, c1 + 1); prevCol1++)
                    {
                        for (int prevCol2 = max(0, c2 - 1); prevCol2 <= min(n - 1, c2 + 1); prevCol2++)
                        {
                            prevRowMax = max(prevRowMax, t[row - 1][prevCol1][prevCol2]);
                        }
                    }
                    if (c1 != c2)
                    {
                        t[row][c1][c2] = prevRowMax + grid[row][c1];
                    }
                    else
                    {
                        t[row][c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result = max(result, t[m - 1][i][j]);
            }
        }
        return result;
    }
    /* --------------------------------- BOTTOM UP 2D DP  ---------------------------------------------*/
    int cherryPickup2(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prev(71, vector<int>(71, 0));
        prev[0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1];

        for (int row = 1; row < m; row++)
        {
            vector<vector<int>> curr(71, vector<int>(71, 0));
            for (int c1 = 0; c1 <= min(n - 1, row); c1++)
            {
                for (int c2 = max(0, n - row - 1); c2 <= n; c2++)
                {
                    int prevRowMax = 0;
                    for (int prevCol1 = max(0, c1 - 1); prevCol1 <= min(n - 1, c1 + 2); prevCol1++)
                    {
                        for (int prevCol2 = max(0, c2 - 1); prevCol2 <= min(n - 1, c2 + 2); prevCol2)
                        {
                            prevRowMax = max(prevRowMax, prev[prevCol1][prevCol2]);
                        }
                    }
                }
                prev = curr;
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result = max(result, prev[i][j]);
            }
        }
        return result;
    }
};
