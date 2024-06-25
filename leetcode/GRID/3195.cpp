#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r1 = -1, c1 = -1, r2 = -1, c2 = -1;

        // Find the topmost row containing a 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    r1 = i;
                    break;
                }
            }
            if (r1 != -1) {
                break;
            }
        }

        // Find the leftmost column containing a 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1) {
                    c1 = i;
                    break;
                }
            }
            if (c1 != -1) {
                break;
            }
        }

        // Find the bottommost row containing a 1
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    r2 = i;
                    break;
                }
            }
            if (r2 != -1) {
                break;
            }
        }

        // Find the rightmost column containing a 1
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1) {
                    c2 = i;
                    break;
                }
            }
            if (c2 != -1) {
                break;
            }
        }

        
        if (r1 == -1 || c1 == -1 || r2 == -1 || c2 == -1) {
            return 0;
        }

        int r = r2 - r1 + 1;
        int c = c2 - c1 + 1;

        return r * c;
    }
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r1 = INT_MAX;
        int c1 = INT_MAX;
        int r2 = INT_MIN;
        int c2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    r1 = min(r1, i);
                    r2 = max(r2, i);
                    c1 = min(c1, i);
                    c2 = max(c2, i);
                }
            }
        }
        int r = r2 - r1 + 1;
        int c = c2 - c1 + 1;
        return r * c;
    }
};
