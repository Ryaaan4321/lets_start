#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    int subarraySum(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int s = 0; s < nums.size(); s++)
        {
            for (int e = s; e < nums.size(); e++)
            {
                int sum = 0;
                for (int i = s; i < e; i++)
                {
                    sum += nums[i];
                }
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    }
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int currsum = 0;
        int ans = 0;
        mpp.insert({0, 1});
        for (int i = 0; i < nums.size(); i++)
        {
            currsum += nums[i];

            if (mpp.find(currsum - k) != mpp.end())
            {
                ans += mpp[currsum - k];
            }
            mpp[currsum]++;
        }
        return ans;
    }
};