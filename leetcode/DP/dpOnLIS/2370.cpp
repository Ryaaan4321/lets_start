#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int solve(int idx, int prev_idx, int k, int n, string s,
              vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][prev_idx] != -1)
        {
            return dp[idx][prev_idx];
        }
        if (abs((s[idx] - 'a') - (prev_idx)) <= k || prev_idx == 26)
        {
            dp[idx][prev_idx] =
                max(1 + solve(idx + 1, s[idx] - 'a', k, n, s, dp),
                    solve(idx + 1, prev_idx, k, n, s, dp));
        }
        else
        {
            dp[idx][prev_idx] = solve(idx + 1, prev_idx, k, n, s, dp);
        }
    }
    int longestIdealString(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(127, -1));
        int ans = solve(0, 26, k, n, s, dp);
        return ans;
    }
};