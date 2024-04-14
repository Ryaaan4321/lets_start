#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
class Solution
{
public:
    int digit_sum(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            int temp = x % 10;
            sum += temp;
            x /= 10;
            /* code */
        }
        return sum;
    }
    int maximumSum(vector<int> &a)
    {
        sort(a.begin(), a.end(), greater<int>());
        int n = a.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int tmp = digit_sum(a[i]);
            mp[tmp].push_back(a[i]);
        }
        int mx = -1;
        for (auto it : mp)
        {
            if (it.second.size() <= 1)
            {
                continue;
            }
            vector<int> tmp = it.second;
            mx = max(mx, tmp[0] + tmp[1]);
        }
        return mx;
    }
};
