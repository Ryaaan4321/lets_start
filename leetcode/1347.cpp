#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); ++i)
        {
            map[i]++;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            map[i]--;
        }
        int ans = 0;
        for (auto p : map)
        {
            if (p.second > 0)
                ans += p.second;
        }
        return ans;
    }
};