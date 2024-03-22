#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int dp[101];
    int n;
    int solve(int idx, vector<int> &nums, int n)
    {
        if (idx >= n)
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        int take = nums[idx] + solve(idx + 2, nums, n);
        int skip = solve(idx + 1, nums, n);

        return dp[idx] = max(take, skip);
    }
    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        // dp[i]=max stolen money till i house;

        if (n == 1)
            return nums[0];

        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(steal, skip);
        }
        return dp[n];
    }
    int rob3(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        int prevprev = 0;
        int prev = nums[0];

        for (int i = 2; i < n; i++)
        {
            int skip = prev;
            int take = nums[i - 1] + prevprev;

            int temp = max(skip, take);

            prevprev = prev;
            prev = temp;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, n);
    }
};