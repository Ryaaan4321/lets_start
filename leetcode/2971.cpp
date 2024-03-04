#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        long long prefSum = nums[0] + nums[1];
        long long ans = 0;

        for (int i = 2; i < nums.size(); ++i)
        {
            if (prefSum > nums[i])
            {
                ans = max(ans, prefSum + nums[i]);
            }
            prefSum += nums[i];
        }
        return (ans == 0) ? -1 : ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    auto s = Solution();
    auto ans = s.largestPerimeter(nums);

    cout << ans << "\n";
}