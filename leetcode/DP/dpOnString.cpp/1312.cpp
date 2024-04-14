#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (s[i] == t[j])
        {
            ans = 1 + solve(s, t, i - 1, j - 1, dp);
        }
        else
        {
            ans = max(solve(s, t, i - 1, j, dp), solve(s, t, i, j - 1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minInsertions(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solve(s, t, n - 1, n - 1, dp);
        return n - ans;
    }
    int minInsertions(string a)
    {
        int n = a.size();
        int dp[2][n + 1];
        for (int i = n; i >= 1; i--)
        {
            dp[i % 2][i] = dp[i % 2][i - 1] = 0;
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i - 1] == a[j - 1])
                    dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
                else
                    dp[i % 2][j] = min(dp[i % 2][j - 1], dp[(i + 1) % 2][j]) + 1;
            }
        }
        return dp[1][n];
    }
};