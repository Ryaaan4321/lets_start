#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    int mod=1e9+7;
    int solve(int idx, vector<int> &nums, int target,vector<vector<int>>&dp)
    {
        if (target==0)
        {
            return 1;
        }
        if (idx == 0)
        {
            return (nums[0]==target)?1:0;
        }
        if (idx > nums.size())
        {
            return 0;
        }
        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }
        int not_take = solve(idx - 1, nums, target,dp);
        int taken = 0;
        if (nums[idx] <= target)
        {
            taken = solve(idx - 1, nums, target - nums[idx],dp);
        }
        return dp[idx][target] = (taken + not_take)%mod;
    }
    int findWays(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int ans = solve(n - 1, arr, k,dp);
        return ans;
    }
};