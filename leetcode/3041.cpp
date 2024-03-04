#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
class Solution
{
public:
    int maxSelectedElements(vector<int> &nums)
    {
        unordered_map<int, int> dp;
        sort(begin(nums), end(nums));
        int ans = 0;
        for (int &el : nums)
        {
            dp[el + 1] = dp[el] + 1;
            dp[el] = dp[el - 1] + 1;
            ans = max({ans, dp[el + 1], dp[el]});
        }
        return ans;
    }
};