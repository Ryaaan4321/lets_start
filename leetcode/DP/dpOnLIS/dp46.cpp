#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int longestBiotonicSequence(vector<int> &a, int n)
    {
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (a[prev] < a[i])
                {
                    dp1[i] = max(dp1[i], 1 + dp1[prev]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = n - 1; prev > i; prev--)
            {
                if (a[prev] < a[i])
                {
                    dp2[i] = max(dp2[i], 1 + dp2[prev]);
                }
            }
        }
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        return maxi;
    }
};
