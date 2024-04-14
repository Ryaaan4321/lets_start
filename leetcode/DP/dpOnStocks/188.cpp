#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
    int fuc(int idx, int by, vector<int> &a, int limit, vector<vector<vector<int>>> &dp)
    {
        if (idx == a.size())
        {
            return 0;
        }
        if (limit == 0)
        {
            return 0;
        }
        if (dp[idx][by][limit] != -1)
        {
            return dp[idx][by][limit];
        }
        int kamai = 0;
        if (by)
        {
            int kharid = -a[idx] + fuc(idx + 1, 0, a, limit, dp);
            int chorde = 0 + fuc(idx + 1, 1, a, limit, dp);
            kamai = max(kharid, chorde);
        }
        else
        {
            int bechde = a[idx] + fuc(idx + 1, 1, a, limit - 1, dp);
            int chorna = 0 + fuc(idx + 1, 0, a, limit, dp);
        }
        dp[idx][by][limit] = kamai;
        return dp[idx][by][limit];
    };
    int maxProfit(int k, vector<int> &a)
    {
        int n = a.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int by = 0; by <= 1; by++)
            {
                for (int lim = 1; lim <= k; lim++)
                {
                    int kamai = 0;
                    if (by)
                    {
                        int kharid = -a[idx] + dp[idx + 1][0][lim];
                        int chorna = 0 + dp[idx + 1][1][lim];
                        kamai = max(kharid, chorna);
                    }
                    else
                    {
                        int bechde = a[idx] + dp[idx + 1][1][lim - 1];
                        int chorde = 0 + dp[idx + 1][0][lim];
                        kamai = max(bechde, chorde);
                    }
                    dp[idx][by][lim] = kamai;
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(vector<int> &a, int k)
    {
        int n = a.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int by = 0; by <= 1; by++)
            {
                for (int lim = 1; lim <= k; lim++)
                {
                    int kamai = 0;
                    if (by)
                    {
                        int kharid = -a[idx] + next[0][lim];
                        int chorna = 0 + next[1][lim];
                        kamai = max(kharid, chorna);
                    }
                    else
                    {
                        int bechde = a[idx] + next[1][lim - 1];
                        int chorde = 0 + next[0][lim];
                        kamai = max(bechde, chorde);
                    }
                    curr[by][lim] = kamai;
                }
                next = curr;
            }
        }
        return next[1][k];
    }
};