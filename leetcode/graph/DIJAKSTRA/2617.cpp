#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    void update(vector<int>& t, int index, int val) {
        int n = t.size()/2;
        t[index+n] = val;
        for (int i = index+n; i > 1; i /= 2) {
            t[i/2] = min(t[i], t[i^1]);
        }
    }
    int query(vector<int>& t, int l, int r) {
        int n = t.size()/2;
        int res = INT_MAX;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) res = min(res, t[l++]);
            if (r&1) res = min(res, t[--r]);
        }
        return res;
    }

    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> rows(n, vector<int>(2*m, INT_MAX));
        vector<vector<int>> cols(m, vector<int>(2*n, INT_MAX));
        
        update(cols[m-1], n-1, 1),
        update(rows[n-1], m-1, 1);
        
        for (int r = n-1; r >= 0; --r) {
            for (int c = m-1; c >= 0; --c) {
                if (r == n-1 && c == m-1) continue;
                
                int move_down = query(rows[r], c+1, min(m-1, c+grid[r][c]));
                int move_right = query(cols[c], r+1, min(n-1, r+grid[r][c]));
                
                int mn = min(move_down, move_right);
                if (mn != INT_MAX) ++mn;
                
                update(cols[c], r, mn);
                update(rows[r], c, mn);
                
                if (!r && !c) return mn == INT_MAX ? -1 : mn;
            }
        }
        
        return 1;
    }
};

/*dijakstra gives tle*/
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