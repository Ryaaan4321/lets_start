#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int dp[23][23];
    int maxDiff(vector<int> &nums, int left, int right, int n)
    {
        if (left == right)
        {
            return nums[left];
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }
        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right, n);
        int scoreByRight = nums[right] - maxDiff(nums, left, right - 1, n);

        return dp[left][right] = max(scoreByLeft, scoreByRight);
    }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return maxDiff(nums, 0, n - 1, n) >= 0;
        // time complexity = O(2^N);
        // space complexity=O(N);
    }
};