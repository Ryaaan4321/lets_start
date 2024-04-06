#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> fuc(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp){

    };
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int max_Idx = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i]>dp[max_Idx]){
                max_Idx=i;
            }
        }
        vector<int> result;
        while (max_Idx != -1)
        {
            result.push_back(nums[max_Idx]);
            max_Idx = prev[max_Idx];
            /* code */
        }
        reverse(result.begin(), result.end());
        return result;
    }
};