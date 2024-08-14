#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &a)
    {
        int n=a.size();
        int mx = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            mx = max(mx, mp[a[i]]);
        }
        vector<vector<int>> grid(mx);
        for (auto it : mp)
        {
            int key = it.first;
            int f = it.second;
            for (int i = 0; i < f; i++)
            {
                grid[i].push_back(key);
            }
        }
        return grid;
    }
};