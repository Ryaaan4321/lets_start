#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 8; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (isValid(nr, nc, n, m) && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        
        bool f = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bool knightCanMove = false;
                    for (int k = 0; k < 8; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (isValid(nr, nc, n, m) && grid[nr][nc] == 1) {
                            knightCanMove = true;
                            break;
                        }
                    }
                    if (!knightCanMove) {
                        f = false;
                        break;
                    }
                }
            }
        }
        
        return f;
    }
};
