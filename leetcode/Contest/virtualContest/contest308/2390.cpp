#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string ans = "";
        for (auto ch : s)
        {
            if (ch == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans += ch;
            }
        }
        return ans;
    }
};