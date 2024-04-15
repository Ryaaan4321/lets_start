#include <bits/stdc++.h>
#include <algorithm>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            ans += abs((s[i] - 'a') - (s[i + 1] - 'a'));
        }
        return ans;
    }
};