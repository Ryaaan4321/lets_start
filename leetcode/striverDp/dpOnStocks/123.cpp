#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int fuc(int idx, int buy, vector<int> &a, int limit, vector<vector<vector<int>>> &dp)
    {
        if (idx == a.size() || limit == 0)
            return 0;

        if (dp[idx][buy][limit] != -1)
        {
            return dp[idx][buy][limit];
        }
        int kamai = 0;
        if (buy)
        {
            int By = -a[idx] + fuc(idx + 1, 0, a, limit, dp);
            int not_take = 0 + fuc(idx + 1, 0, a, limit, dp);
            kamai = max(By, not_take);
        }
        else
        {
            int sl = a[idx] + fuc(idx + 1, 1, a, limit - 1, dp);
            int not_taken = 0 + fuc(idx + 1, 0, a, limit, dp);
            kamai = max(sl, not_taken);
        }
        dp[idx][buy][limit] = kamai;
        return dp[idx][buy][limit];
    }
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fuc(0, 0, a, 0, dp);
    }
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx++)
        {
            for (int by = 0; by <= 1; by++)
            {
                for (int lim = 1; lim <= 2; lim++)
                {
                    int kamai = 0;
                    if (by)
                    {
                        int kharid = -a[idx] + dp[idx + 1][0][lim];
                        int chorde = 0 + dp[idx + 1][1][lim];
                        kamai = max(kharid, chorde);
                    }
                    else
                    {
                        int bechde = a[idx] + dp[idx + 1][1][lim];
                        int chorna = 0 + dp[idx + 1][0][lim];
                        kamai = max(bechde, chorna);
                    }
                    dp[idx][by][lim] = kamai;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int> &prices)
    {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for (auto x : prices)
        {
            buy1 = min(buy1, x);
            profit1 = max(profit1, x - buy1);
            buy2 = min(buy2, x - profit1);
            profit2 = max(profit2, x - buy2);
        }
        return profit2;
    }
};