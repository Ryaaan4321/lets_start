#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
/*you gotta be almost insane to your craft - Sir mcgregor*/
class Solution
{
public:
    int dp[1002];
    int n;
    int solve(int idx, vector<int> &cost)
    {
        n = cost.size();
        if (idx >= n)
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        int ans = 0;
        int one=cost[idx]+solve(idx+1,cost);
        int two=cost[idx]+solve(idx+2,cost);
        ans=min(one,two);

        return dp[idx] = ans;
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        n=cost.size();
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost),solve(1,cost));
        /*becuase we can start from either from the idx 1 or either from the idx2;*/
    }
};