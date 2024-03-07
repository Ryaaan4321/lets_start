#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>> &pairs, int prev_idx, int curr_idx)
    {
        if (curr_idx == n)
        {
            return 0;
        }
        int taken = 0;
        if (prev_idx == -1 || pairs[curr_idx][0] > pairs[prev_idx][1])
        {
            taken = 1 + solve(pairs, curr_idx, curr_idx + 1);
        }
        int skip = solve(pairs, prev_idx, curr_idx + 1);

        if (prev_idx != -1)
        {
            dp[prev_idx][curr_idx] = max(taken, skip);
        }
        return max(taken, skip);
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        memset(dp, -1, sizeof(dp));
        sort(begin(pairs), end(pairs));
        return solve(pairs, -1, 0);
    }
};
