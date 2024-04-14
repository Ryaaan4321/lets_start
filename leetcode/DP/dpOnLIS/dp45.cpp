#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool check(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
        {
            return 0;
        }
        int first = 0;
        int second = 0;

        while (first < s1.size())
        {
            if (second < s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }

        if (first == s1.size() && second == s2.size())
            return 1;
        else
            return 0;
    }

    int longestStrChain(vector<string> &s)
    {
        auto comp = [](const string &s1, const string &s2)
        {
            return s1.size() < s2.size();
        };
        int n = s.size();
        sort(s.begin(), s.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (check(s[i], s[prev]) && dp[i] < dp[prev] + 1)
                {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};