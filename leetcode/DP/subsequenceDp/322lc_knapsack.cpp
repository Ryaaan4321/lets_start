#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    
    int solve(int idx, vector<int> &coins, int amt, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (amt % coins[0] == 0)
            {
                return amt / coins[0];
            }
            return 1e9;
        }
        if (dp[idx][amt] != -1)
        {
            return dp[idx][amt];
        }
        int nottake = solve(idx - 1, coins, amt, dp);
        int take = 1e9;
        if ((coins[idx] <= amt))
        {
            take = 1 + solve(idx, coins, amt - coins[idx], dp);
        }
        return dp[idx][amt] = min(take, nottake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int  n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, coins, amount, dp);
        if (ans == 1e9)
        {
            return -1;
        }
        return ans;
    }
};