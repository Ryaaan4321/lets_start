#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool result = false;
    int n;
    int dp[100009];
    bool solve(int idx, vector<int> &a)
    {

        if (idx >= n)
        {
            return true;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        if (idx + 1 < n && a[idx] == a[idx + 1])
        {
            result |= solve(idx + 2, a);
        }
        if (idx + 2 < n && a[idx] == a[idx + 1] && a[idx] == a[idx + 2])
        {
            result |= solve(idx + 3, a);
        }
        if (idx + 2 < n && a[idx + 1] - a[idx] == 1 && a[idx + 2] - a[idx + 1] == 1)
        {
            result |= solve(idx + 3, a);
        }
        return dp[idx] = result;
    }
    bool validPartition(vector<int> &nums)
    {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};