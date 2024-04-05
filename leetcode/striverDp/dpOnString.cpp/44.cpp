#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isAllStar(string &s, int i)
    {
        for (int j = 0; j <= i; j++)
        {
            if (s[j] != '*')
            {
                return 0;
            }
            
        }
        return 1;
    };
    bool fuc(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
        {
            return 1;
        }
        if (i < 0 && j >= 0)
        {
            return 0;
        }
        if (j < 0 && i >= 0)
        {
            return isAllStar(s, i);
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j] || s[i] == '?')
        {
            return dp[i][j] = fuc(i - 1, j - 1, s, t, dp);
        }
        else
        {
            if (s[i] == '*')
            {
                return dp[i][j] = fuc(i - 1, j, s, t, dp) || fuc(i, j - 1, s, t, dp);
            }
            else
            {
                return 0;
            }
        }
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fuc(n - 1, m - 1, s, p, dp);
    }
};
