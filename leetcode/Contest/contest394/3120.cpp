#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int cnt=0;
    bool isvalid(int i, int j, int n, int m, vector<vector<bool>>& visited) {
        return (i < n) && (j < m) && (visited[i][j] == true);
    }
    int dfs(int i, int j, int n, int m, vector<vector<bool>>& visited,
            vector<vector<int>>& grid) {
        if (!isvalid(i, j,n,m,visited)) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               visited[i][j] = 1;

                if (isvalid(i, j, n, m, visited) &&
                    grid[i][j] != grid[i + 1][j]) {
                    cnt++;
                }
                else if (isvalid(i, j, n, m, visited) &&
                    grid[i][j] == grid[i][j + 1]) {
                    cnt++;
                } else {
                    continue;
                }
                dfs(i + 1, j, n, m, visited, grid);
                dfs(i, j + 1, n, m, visited, grid);
            }
        }
        return cnt;
       
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        cnt=0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j]=1;
                if (!visited[i][j]) {
                    dfs(i, j, n, m, visited, grid);
                }
            }
        }
        return cnt;
    }
};