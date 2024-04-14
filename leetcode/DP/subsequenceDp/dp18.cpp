#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    int solve(int idx, vector<int> &nums, int target, vector<vector<int>> &dp)
    {

        if (idx == 0)
        {
            if (target == 0 && nums[0] == 0)
            {
                return 2;
            }
            if (target == 0 || target == nums[0])
            {
                return 1;
            }
            return 0;
        }
        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }
        int skip = solve(idx - 1, nums, target, dp);
        int taken = 0;
        if (nums[idx] <= target)
        {
            taken = solve(idx - 1, nums, target - nums[idx], dp);
        }
        return dp[idx][target] = (skip + taken) % mod;
    };
    int countPartitions(int n, int d, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return solve(n - 1, arr, d, dp);
    }
};