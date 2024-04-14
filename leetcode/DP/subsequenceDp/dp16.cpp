#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int totsum = 0;
        for (int i = 0; i < n; i++)
        {
            totsum += arr[i];
        }
        vector<vector<bool>> dp(n, vector<bool>(totsum + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if (arr[0] <= totsum)
        {
            dp[0][totsum] = 1;
        }
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= totsum; target++)
            {
                bool skip = dp[idx - 1][target];

                bool taken = 0;

                if (arr[idx] <= target)
                {
                    taken = dp[idx - 1][target - arr[idx]];
                }
                dp[idx][target] = skip || taken;
            }
        }

        int mini = 1e9;
        //if u didnt get this part when u are revising then visit to this 
        //link :- https://takeuforward.org/data-structure/partition-set-into-2-subsets-with-min-absolute-sum-diff-dp-16/
        for (int i = 0; i < totsum; i++)
        {
            if (dp[n - 1][i] = true)
            {
                int diff = abs(i - (totsum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};