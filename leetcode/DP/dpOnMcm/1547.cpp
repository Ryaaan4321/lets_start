#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int dp[109][109];
    int fuc(int l, int r, int i, int j, vector<int> &a)
    {
        if (l >= r)
        {
            return 0;
        }
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return r - l;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int idx = i; idx <= j; idx++)
        {
            long long res = r - l + fuc(l, a[idx], i, idx - 1, a) + fuc(a[idx], r, idx + 1, j, a);
            ans = min(ans, (int)res);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int> &a)
    {
        sort(a.begin(), a.end());
        memset(dp,-1,sizeof(dp));
        return fuc(0, n, 0, a.size() - 1, a);
    }
};