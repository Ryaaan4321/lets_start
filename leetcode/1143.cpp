#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    string text1, text2;

    int solve(int i, int j)
    {
        if (i >= text1.size() || j >= text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j]; // if it is no elm than return the current the dp[i][j];

        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solve(i + 1, j + 1);
        }
        else
        {
            ans = max(solve(i, j + 1), solve(i + 1, j));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence1(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        this->text1 = text1;
        this->text2 = text2;

        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return solve(0, 0);
    }

public:
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