#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> count(char ch, vector<vector<char>> grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> pref(row, vector<int>(col, 0));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                pref[r][c] = (grid[r][c] == ch) ? 1 : 0;
            }
        }
        /* finding out the 2D-prefix sum in the rowwise direction*/
        for (int r = 0; r < row; r++) {
            for (int c = 1; c < col; c++) {
                pref[r][c] += pref[r][c - 1];
            }
        }
        /* finding out the 2D-prefix sum in the colwise direction*/
        for (int r = 1; r < row; r++) {
            for (int c = 0; c < col; c++) {
                pref[r][c] += pref[r - 1][c];
            }
        }
        return pref;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> c_x = count('X', grid);
        vector<vector<int>> c_y = count('Y', grid);
        int res = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (c_x[r][c] == c_y[r][c] && c_x[r][c] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};