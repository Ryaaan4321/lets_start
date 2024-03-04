#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1];
        int cnt = 0;
        for (int i = 2; i < nums.size(); ++i)
        {
            if (sum > nums[i])
            {
                cnt++;
            }
            sum+=nums[i];
        }
        return cnt;
    }
};