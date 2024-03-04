#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int num : nums)
        {
            mpp[num]++;
            
        }
        for (auto &it : mpp)
        {
            if (it.second >= nums.size() / 2)
            {
                return it.first;
            }
        }
        return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    Solution obj;
    int ans = obj.majorityElement(a);
    cout << ans << endl;
    return 0;
}