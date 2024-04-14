#include <bits/stdc++.h>
#include <algorithm>
#include <malloc.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    int fuc(int idx, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][buy] != -1)
        {
            return dp[idx][buy];
        }
        int profit = 0;
        if (buy == 0)
        {
            profit = max(0 + fuc(idx + 1, 0, n, prices, dp), -prices[idx] + fuc(idx + 1, 1, n, prices, dp));
        }
        else if (buy == 1)
        {
            profit = max(0 + fuc(idx + 1, 1, n, prices, dp), prices[idx] + fuc(idx + 1, 0, n, prices, dp));
        }
        return dp[idx][buy] = profit;
    };
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        if (n == 0)
        {
            return 0;
        }
        int ans = fuc(0, 0, n, prices, dp);
        return ans;
    }
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};