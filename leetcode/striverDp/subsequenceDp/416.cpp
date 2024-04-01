#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solve(int idx, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            return nums[0] == target;
        };
        if (target == 0)
        {
            return 1;
        }
        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }

        bool skip = solve(idx - 1, target, nums, dp);
        bool take = 0;
        if (nums[idx] <= target)
        {
            take = solve(idx - 1, target - nums[idx], nums, dp);
        }

        return dp[idx][target] = skip || take;
    };
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if ((tot & 1))
        {
            return 0;
        }
        int k = tot / 2;
        vector<vector<int>> dp(n, vector<int>(tot + 1, -1));
        return solve(n - 1, k, nums, dp);
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false; // If the sum is odd, partition is not possible
        int k = sum / 2;

        bitset<10001> bs; // Assuming maximum possible sum is 10000 (as per the problem constraints)
        bs[0] = 1;        // Initialize bs with 1 at index 0 (indicating sum of 0 is possible)

        for (auto &x : nums)
            bs |= bs << x; // Set the bits at indices representing possible sums

        return bs[k]; // Check if the sum k can be achieved
    }
};