#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
    int dp[1001][1001];
    int solve(int i, int j, string s, string t)
    {
        if (i == s.size())
        {
            return 0;
        }
        if (j == t.size())
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = solve(i + 1, j, s, t);
        if (s[i] == t[j])
        {
            ans += solve(i + 1, j + 1, s, t);
        }
        return dp[i][j] = ans;
    };
    int numDistinct(string s, string t)
    {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        int m = t.size();
        return solve(0, 0, s, t);
    }
    int numsDistinct(string s, string t)
    {
        return dfs(0, 0, s, t);
    };
    map<pair<int, int>, int> cache;
    int dfs(int i, int j, string &s, string &t)
    {
        if (j == t.size())
        {
            return 1;
        }
        if (i == s.size())
        {
            return 0;
        }
        if (cache.find({i, j}) != cache.end())
        {
            return cache[{i, j}];
        }
        if (s[i] == t[j])
        {
            cache[{i, j}] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        }
        else
        {
            cache[{i, j}] = dfs(i + 1, j, s, t);
        }
        return cache[{i, j}];
    }
    int numDistinct(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();

        vector<unsigned int> dp(n2 + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == t[0] ? 1 : 0;
        for (int i = 2; i <= n1; i++)
        {
            for (int j = min(i, n2); j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return static_cast<int>(dp[n2]);
    }
};