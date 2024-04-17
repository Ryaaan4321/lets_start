#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &a)
    {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[i] - i != a[j] - j)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    long long countBadPairs(vector<int> &a)
    {
        unordered_map<long long, long long> mp;
        long long good_pairs = 0;
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            long long cals = a[i] - i;
            if (mp.find(cals) != mp.end())
            {
                good_pairs += mp[cals];
            }
            mp[cals]++;
        }
        if (mp.size() <= 1)
        {
            return 0;
        }
        long long total_pair = n * (n + 1 / 2);
        return total_pair - good_pairs;
    }
};