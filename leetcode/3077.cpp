#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int n;

    vector<vector<vector<long long>>> dp;
    long long solve(int i, long long k, vector<int> &nums, bool start_new)
    {
        if (k == 0)
        {
            return 0;
        }
        if (i >= n)
        {
            return -1e18;
        }
        if (dp[i][k][start_new] != -1)
        {
            return dp[i][k][start_new];
        }
        long long not_take = -1e18;
        long long take = -1e18;

        if (start_new == true)
        {
            not_take = solve(i + 1, k, nums, true);
        }

        if (k % 2 != 0)
        {
            take = solve(i + 1, k, nums, false) + nums[i] * k;
            take = max(take, solve(i + 1, k - 1, nums, true) + nums[i] * k);
        }
        else
        {
            take = solve(i + 1, k, nums, false) - nums[i] * k;
            take = max(take, solve(i + 1, k - 1, nums, true) - nums[i] * k);
        }
        return dp[i][k][start_new] = max(not_take, take);
    }

    long long maximumStrength(vector<int> &nums, int k)
    {
        n = nums.size();
        dp.resize(n + 1, vector<vector<long long>>(k + 1, vector<long long>(2, -1)));
        bool start_new = true;
        return solve(0, k, nums, start_new);
    }
};