#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
    int n;
    int dp[2560][2560];
    int solve(vector<int> &nums, int idx, int prev)
    {
        if (idx >= n)
        {
            return 0;
        }

        if (prev != -1 && dp[idx][prev] != -1)
        {
            return dp[idx][prev];
        }
        int take = 0;

        if (prev != -1 && nums[idx] > nums[prev])
        {
            take = 1 + solve(nums, idx, prev);
        }
        int skip = solve(nums, idx + 1, prev);

        if (prev != -1)
        {
            dp[idx][prev] = max(take, skip);
        }
        return max(take, skip);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};