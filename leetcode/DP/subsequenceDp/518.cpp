#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solve(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
        {
            return 1;
        }
        if (amount < 0 || idx >= coins.size()) 
            return 0;

        if (dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        int take = solve(idx, amount - coins[idx], coins, dp);
        int skip = solve(idx + 1, amount, coins, dp);

        dp[idx][amount] = take + skip;
        return dp[idx][amount];
    };
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }
};
