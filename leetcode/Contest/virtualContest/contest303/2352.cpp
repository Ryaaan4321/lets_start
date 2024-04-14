#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int cnt = 0;
        for (int ro = 0; ro < n; ro++)
        {
            for (int co = 0; co < n; co++)
            {
                bool isEqual = 1;
                for (int i = 0; i < n; i++)
                {
                    if (grid[ro][i] != grid[i][co])
                    {
                        isEqual = 0;
                    }
                }
                if (isEqual)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> mp;
        for (int ro = 0; ro < grid.size(); ro++)
        {
            mp[grid[ro]]++;
        }
        int cnt = 0;
        for (int co = 0; co < grid.size(); co++)
        {
            vector<int> ans;
            for (int r = 0; r < grid.size(); r++)
            {
                ans.push_back(grid[r][co]);
            }
            cnt += mp[ans];
        }
        return cnt;
    }
};