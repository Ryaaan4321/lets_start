#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        map<string, int> mp;
        for (auto &cr : matrix)
        {
            string pattern = "";
            for (int i = 0; i < cr.size(); i++)
            {
                if (cr[0] == cr[i])
                {
                    pattern += "T";
                }
                else
                {
                    pattern += "F";
                }
            }
            mp[pattern]++;
        }
        int f = 0;
        for (auto &it : mp)
        {
            f = max(it.second, f);
        }
        return f;
    }
};