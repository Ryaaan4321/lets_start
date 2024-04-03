#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int solve(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 || idx2 < 0)
        {
            return 0;
        }
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }
        if (s1[idx1] == s2[idx2])
        {
            return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, s1, s2, dp), solve(idx1, idx2 - 1, s1, s2, dp));
        }
    };
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, text1, text2, dp);
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int j = m - 1; j >= 0; --j)
        {
            for (int i = n - 1; i >= 0; --i)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};