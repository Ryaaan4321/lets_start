#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int val = numsDivide[0];
        for (auto it : numsDivide)
        {
            val = __gcd(val, it);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (val % nums[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};