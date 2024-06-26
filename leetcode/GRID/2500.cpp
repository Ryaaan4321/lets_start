#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        int _sm = 0;
        for (int col = grid[0].size() - 1; col >= 0; col--) {
            int mx = INT_MIN;
            for (int ro = 0; ro < grid.size(); ro++) {
                mx = max(mx, grid[ro][col]);
            }
            _sm += mx;
        }
        return _sm;
    }
};