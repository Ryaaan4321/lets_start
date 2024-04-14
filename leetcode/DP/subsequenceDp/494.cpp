#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solve(int idx, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
        {
            if (target == 0)
                return 1;
            return 0;
        }

        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }

        int not_taken = solve(idx + 1, nums, target, dp);
        int taken = 0;
        if (nums[idx] <= target)
        {
            taken = solve(idx + 1, nums, target - nums[idx], dp);
        }
        return dp[idx][target] = taken + not_taken;
    };
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int n = nums.size();
        int sum_total = 0;
        for (int i = 0; i < n; i++)
        {
            sum_total += nums[i];
        }
        int new_target = (target + sum_total);
        if (new_target % 2 != 0 || new_target < 0)
        {
            return 0;
        }
        new_target /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(new_target + 1, -1));
        if (target > sum_total)
        {
            return 0;
        }
        if (n == 1)
        {
            if (target == nums[0] || target == (-1 * nums[0]))
            {
                return 1;
            }
            return 0;
        }
        return solve(0, nums, new_target, dp);
    }
};