#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool srflip(vector<vector<int>>& grid, int ro, int m) {
        return grid[ro][0] == 0;
    }
    void fliprow(vector<vector<int>>& grid, int ro, int m) {
        for (int j = 0; j < m; j++) {
            grid[ro][j] ^= 1;
        }
    }
    bool scflip(vector<vector<int>>& grid, int co, int n) {
        int o = 0, z = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][co] == 0)
                z++;
            else{
                o++;
            }    
        }
        return o < z;
    }
    void flipc(vector<vector<int>>& grid, int co, int n) {
        for (int i = 0; i < n; i++) {
            grid[i][co] ^= 1;
        }
    }
    int calc(vector<vector<int>> grid, int n, int m) {
        int sm = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0, pow = 1;
            for (int j = m - 1; j >= 0; j--) {
                cur += (pow * grid[i][j]);
                pow *= 2;
            }
            sm += cur;
        }
        return sm;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (srflip(grid, i,m )) {
                fliprow(grid, i, m);
            }
        }
        for (int j = 0; j < m; j++) {
            if (scflip(grid, j, n)) {
                flipc(grid, j, n);
            }
        }
        return calc(grid, n, m);
    }
};
