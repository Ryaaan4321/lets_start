#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
/*you gotta be almost insane to your craft - mc gregor*/
class Solution {
public:
    bool isvalid(int s, int e, vector<int>& a) {
        int n = a.size();
        for (int i = s; i < e; i++) {
            if (i + 1 <= n && a[i] & 1 && a[i + 1] & 1) {
                return false;
            }
            if (i + 1 <= n && a[i] % 2 == 0 && a[i + 1] % 2 == 0) {
                return false;
            }
        }
        return true;
    }
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<bool> ans(n);
        int k = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int fr = grid[i][0];
                int to = grid[i][1];
                if (isvalid(fr, to, a)) {
                    ans[i] = true;
                } else if (!isvalid(fr, to, a)) {
                    ans[i] = false;
                }
            }
        }
        return ans;
    }
};
/*tle in the second last test case*/