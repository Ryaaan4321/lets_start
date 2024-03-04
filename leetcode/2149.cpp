#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
class Solution
{
public:
    // 3 1 -2 -5 2 -4
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
        }
        for (int i = 0; i < pos.size(); i++)
        {
            ans[2 * i] = pos[i];
        }
        for (int j = 1; j < neg.size(); j++)
        {
            ans[2 * j + 1] = neg[j];
        }

        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    auto s = Solution();
    auto ans = s.rearrangeArray(a);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << "\n";
    }
}