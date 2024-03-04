#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int min_len = 1e6;
        int i = 0;
        int j = nums.size();
        int suml = 0;
        while (j < nums.size())
        {
            suml += nums[j];
            while (suml >= target)
            {
                min_len = min(min_len, j - i + 1);
                suml -= nums[i];
                i++;
                /* code */
            }
            j++;

            /* code */
        }
        return min_len;
    }
};