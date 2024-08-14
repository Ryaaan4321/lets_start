#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<long long>> distance(row,(vector<long long>(col,1e9)));
        distance[0][0]=1;
        priority_queue<pair<long long,pair< int, int>>, vector<pair<long long,pair< int, int>>>, greater<pair<long long,pair< int, int>>>> pq;
        pq.push({1,{0, 0}} );
        while (!pq.empty()) {
           auto node=pq.top();
           int d=node.first;
           int curx=node.second.first;
           int cury=node.second.second;
            pq.pop();
            if (curx == row-1 && cury == col-1) {
                return (int)d;
            }
            for (int k = cury+1; k <= min(cury+grid[curx][cury], col-1); k++) {
                if (distance[curx][k] > d+1) {
                    distance[curx][k] = d+1;
                    pq.push({d+1,{curx, k}});
                    if (curx == row-1 && k == col-1) {
                        return (int)d+1;
                    }
                }
            }
            for (int k = curx+1; k <= min(curx+grid[curx][cury], row-1); k++) {
                if (distance[k][cury] > d+1) {
                    distance[k][cury] = d+1;
                    pq.push({d+1, {k, cury}});
                    if (k == row-1 && cury == col-1) {
                        return (int)d+1;
                    }
                }
            }
        }
        return -1;
    }
};