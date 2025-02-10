#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        int step = 0;
        int current = 0;
        vector<bool> ans(n);
        while (!ans[current])
        {
            ans[current] = true;
            step++;
            current = (current + step * k) % n;
        }
        vector<int> a;
        for (int i = 0; i < ans.size(); i++)
        {
            if (!ans[i])
                a.push_back(i + 1);
        }
        return a;
    }
};