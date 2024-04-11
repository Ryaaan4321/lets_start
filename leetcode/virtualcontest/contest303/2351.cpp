#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_map<int, char> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            if (mp[s[i]] > 2)
            {
                return s[i];
            }
        }
        return -1;
    }
};