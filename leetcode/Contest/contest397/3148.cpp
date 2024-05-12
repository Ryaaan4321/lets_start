#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
/*you gotta  be almost insane to your craft - sir mc gregor*/
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >=0; j--) {
                dp[i][j] = grid[i][j];
                if (i + 1 < n) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                    ans = max(ans, dp[i + 1][j] - grid[i][j]);
                }
                if (j + 1 < m) {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                    ans = max(ans, dp[i][j + 1] - grid[i][j]);
                }
            }
        }
        return ans;
    }
};
