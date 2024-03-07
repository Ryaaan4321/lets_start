#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int n;
    int dp[101];
    int solve(vector<int> &nums, int i, int n)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
        {
            return dp[i];
        }
        /*
        so we have a roober here who wants to steal the money
        and the condition is he cant steal the money from th adjacnet
        houses so we have a option either he chooses to steal money
        from that house either skip tht house*/

        int take = nums[i] + solve(nums, i + 2, n); // conditon where he choose to take that house
        int skip = solve(nums, i + 1, n);           // condition where he chooses to skip that house;

        return dp[i] = max(skip, take);
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
        return solve(nums, 0, n);
    }
};