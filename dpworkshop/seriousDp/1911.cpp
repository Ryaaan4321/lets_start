#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int n;
    int dp[1000001][2];
    long long solve(int idx, vector<int> &nums, bool flag)
    {
        if (idx >= n)
        {
            return 0;
        }

        if (dp[idx][flag] != -1)
        {
            return dp[idx][flag];
        }

        long long skip = solve(idx + 1, nums, flag);
        long long val = nums[idx];

        if (flag == false)
        {
            val -= val;
        }
        long long take = solve(idx + 1, nums, !flag) + val;
        return dp[idx][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 1);
    }
    long long maxAlernatingSum(vector<int> &nums)
    {
        long long odd = 0, even = 0;
        for (int &a : nums)
        {
            even = max(even, odd + a);
            odd = even - a;
        }
        return even;
    }
};