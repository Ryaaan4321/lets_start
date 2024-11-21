#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, 1, 0, -1};
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0));
        for (auto& it : guards) {
            g[it[0]][it[1]] = 2;
        }
        for (auto& it : walls) {
            g[it[0]][it[1]] = 2;
        }
        for (auto& it : guards) {
            for (int i = 0; i < 4; i++) {
                int x = it[0];
                int y = it[1];
                while (isvalid(x + dirx[i], y + diry[i], m, n)) {
                    x += dirx[i];
                    y += diry[i];
                    if (g[x][y] == 2)
                        break;
                    if (g[x][y] == 0)
                        g[x][y] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
