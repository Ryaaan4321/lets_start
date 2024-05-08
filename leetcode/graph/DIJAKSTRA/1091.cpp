#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }    
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0] = 1;
        pq.push({1, {0, 0}});
        while (!pq.empty()) {
            pair<int, pair<int, int>> tmp = pq.top();
            int dis = tmp.first;
            int row = tmp.second.first;
            int col = tmp.second.second;
            pq.pop();

            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int newrow = row + delrow;
                    int newcol = col + delcol;
                    if (isvalid(newrow, newcol, n, m) &&
                        grid[newrow][newcol] == 0) {
                        if (distance[newrow][newcol] > dis + 1) {
                            distance[newrow][newcol] = dis + 1;
                            pq.push({distance[newrow][newcol], {newrow, newcol}});
                        }
                    }
                }
            }
        }
        if (distance[n - 1][m - 1] != 1e9) {
            return distance[n - 1][m - 1];
        }
        return -1;
    }
};