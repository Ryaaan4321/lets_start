#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dp[103];
    int n;
    int solve(vector<int> &nums, int i, int n)
    {
        if (i > n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int take = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int> &nums)
    {
        n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        memset(dp, -1, sizeof(dp));

        int take_istIdx = solve(nums, 0, n - 2);
        memset(dp, -1, sizeof(dp));
        int take_secndIdx = solve(nums, 1, n - 1);

        return max(take_istIdx, take_secndIdx);
    }
};