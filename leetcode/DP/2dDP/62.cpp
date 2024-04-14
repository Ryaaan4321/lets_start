#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dp[103][103];
    int solve(int i, int j, int m, int n)
    {
        if (i > n || j > m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = solve(i + 1, j, m, n);
        int down = solve(i, j + 1, m, n);

        return dp[i][j] = right + down;
    };
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, m, n);
        return ans;
    }
};
