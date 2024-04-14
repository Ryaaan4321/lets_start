#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        int n = s.size();
        int m = t.size();

        if (i > n || j >= m)
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
            ans = 1 + solve(s, t, i + 1, j + 1, dp);
        }
        else
        {
            ans = max(solve(s, t, i, j + 1, dp), solve(s, t, i + 1, j, dp));
        }
        dp[i][j] = ans;
        return (n - dp[n][m]) + (m - dp[n][m]);
    };
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = solve(word1, word2, 0, 0, dp);
        return ans;
    }
    int minDistance(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (s1[i - 1] == s2[j - 1]) ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return (n - dp[n][m]) + (m - dp[n][m]);
    }
};