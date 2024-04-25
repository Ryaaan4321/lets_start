#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int n;
    int m;
    vector<vector<int>> res;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool isvalid(int i,int j){
        return (i>=0) && (i<n) && (j>=0) && (j<m);
    }
    void dfs(int i,int j,int &r2,int &c2,vector<vector<int>> &land){
        land[i][j]=0;
        r2=max(r2,i);
        c2=max(c2,j);

        for(auto &dir:directions){
            int n_row=dir[0]+i;
            int n_col=dir[1]+j;

            if(isvalid(n_row,n_col) && land[n_row][n_col]==1){
                dfs(n_row,n_col,r2,c2,land);
            }

        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        n=land.size();
        m=land[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r1=i;
                int c1=j;
                int r2=-1;
                int c2=-1;

                dfs(r1,c1,r2,c2,land);
                res.push_back({r1,c1,r2,c2});
            }
        }
        return res;
    }
};