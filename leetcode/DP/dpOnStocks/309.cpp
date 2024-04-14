#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int fuc(int idx, int by, vector<int> &a, vector<vector<int>> &dp)
    {
        int n = a.size();
        if (idx >= n)
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
            kamai = max(-a[idx] + fuc(idx + 1, 0, a, dp), fuc(idx + 1, 1, a, dp));
        }
        else
        {
            kamai = max(a[idx] + fuc(idx + 2, 1, a, dp), fuc(idx + 1, 0, a, dp));
        }
        return dp[idx][by] = kamai;
    };
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fuc(0, 0, a, dp);
    }
};