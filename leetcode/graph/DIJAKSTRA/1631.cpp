#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    int minimumEffortPath(vector<vector<int>> &grid)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[4] = {-1, 0, +1, 0};
        int dc[4] = {0, +1, 0, -1};
        while (!pq.empty())
        {
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();
            int diff = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            if(row==n-1 && col==m-1){
                return diff;
            }

            for (int i = 0; i < 4; i++)
            {
                int newrow = row + dr[i];
                int newcol = col + dc[i];
                if (isvalid(newrow, newcol, n, m))
                {
                    int eff = max(abs(grid[newrow][newcol] - grid[row][col]), diff);
                    if (distance[newrow][newcol] > eff)
                    {
                        distance[newrow][newcol] = eff;
                        pq.push({eff, {newrow, newcol}});
                    }
                }
            }
        }
        return 0;
    }
};