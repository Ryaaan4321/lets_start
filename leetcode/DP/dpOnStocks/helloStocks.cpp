#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &a)
    {
        int mini = a[0];
        int profit=0;

        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            int cost = a[i]-mini;
            profit = max(profit, cost);
            mini = min(mini, a[i]);
        }
        return profit;
    }
};