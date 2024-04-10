#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &a, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto it : queries)
        {
            int n = a.size();
            vector<pair<string, int>> v;
            for (int j = 0; j < a.size(); j++)
            {
                string sub = a[j].substr(a[j].size() - it[1]);
                v.push_back({sub, j});
            }
            sort(v.begin(), v.end());
            int k = it[0] - 1;
            ans.push_back(v[k].second);
        }
        return ans;
    }
};