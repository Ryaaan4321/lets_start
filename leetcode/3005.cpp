#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int it : nums)
        {
            mpp[it]++;
        }
        int mini = INT_MIN;
        for (auto it : mpp)
        {
            if (it.second > mini)
            {
                mini = it.second;
            }
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==mini){
                ans+=it.second;

            }
        }
        return ans;
    }
};