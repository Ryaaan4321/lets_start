#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += nums[i];
        }
        return sum - sum1;
    }
};