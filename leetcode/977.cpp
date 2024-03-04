#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int p = nums[i] * nums[i];
            ans.push_back(p);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<int> sortedSquares1(vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = n - 1;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int val;
            if (abs(nums[left]) < abs(nums[right]))
            {
                val = nums[right];
                right--;
            }
            else
            {
                val = nums[left];
                left++;
            }
            ans[i] = val * val;
        }
        return ans;
    }
};
