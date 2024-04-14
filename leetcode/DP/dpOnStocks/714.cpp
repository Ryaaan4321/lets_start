#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int dp[50001][2];
    int fuc(int idx, int by, int fee, vector<int> &a)
    {
        if (idx == a.size())
        {
            return 0;
        }
        if (dp[idx][by] != -1)
        {
            return dp[idx][by];
        }
        int kamai = 0;
        if (by)
        {
            int kharid = -a[idx] + fuc(idx + 1, 0, fee, a);
            int chorde = 0 + fuc(idx + 1, 1, fee, a);
            kamai = max(kharid, chorde);
        }
        else
        {
            int bechde = a[idx] - fee + fuc(idx + 1, 1, fee, a);
            int rehnde = 0 + fuc(idx + 1, 0, fee, a);
            kamai = max(bechde, rehnde);
        }
        dp[idx][by] = kamai;
        return kamai;
    }
    int maxProfit(vector<int> &a, int fee)
    {
        memset(dp, -1, sizeof(dp));
        return fuc(0, 1, fee, a);
    }
};