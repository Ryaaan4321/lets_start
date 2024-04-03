#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, string &s, vector<vector<int>> &dp)
    {
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        reverse(s.begin(),s.end());

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int tick = 0;
                int notick = 0;
                if (s[i - 1] == t[j - 1])
                {
                    tick += 1 + dp[i - 1][j - 1];
                }
                else
                {
                    notick = max(dp[i - 1][j], dp[i][j - 1]);
                }
                dp[i][j] = max(tick, notick);
            }
        }
        return dp[n][n];
    }
};