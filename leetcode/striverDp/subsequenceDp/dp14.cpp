#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dp[10002][10002];
    int solve(int i, int target, vector<int> &ar, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return ar[0]=target;
        }
        if (target == 0)
        {
            return 1;
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        bool nottake = solve(i - 1, target, ar, dp);

        bool take = false;

        if (ar[i] <= target)
        {
            bool take = solve(i - 1, target - ar[i], ar, dp);
        }
        return dp[i][target] = take || nottake;
    };

    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return solve(n-1, k, arr, dp);
    }
};