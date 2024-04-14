#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int fuc(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][prev_idx + 1] != -1)
        {
            return dp[idx][prev_idx + 1];
        }
        int not_take = 0 + fuc(idx + 1, prev_idx, nums, dp);

        int take = 0;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx])
        {
            take = 1 + fuc(idx + 1, idx, nums, dp);
        }
        return dp[idx][prev_idx + 1] = max(take, not_take);
    };

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fuc(0, -1, nums, dp);
    }
};