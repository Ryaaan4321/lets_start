#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<bool>used;
    vector<int>component;
    stack<int>st;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void checkcomponent(vector<vector<int>>&grid,int v){
        st.push(v);
        while (!st.empty())
        {
          int node=st.top();
          st.pop();
          if(!used[node]){
            used[node]=1;
            component.push_back(node);
            for(int i=grid[node].size()-1;i>=0;i--){
                st.push(grid[node][i]);
            }
          }
        }
    }
    int bfs(int i,int j,vector<vector<int>>&grid){
        priority_queue<pair<int,int>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        pq.push({i,j});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--)
            {
                auto node=pq.top();
                pq.pop();
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nj=j+dc[k];
                    
                }
            }
        }

    }
    int containVirus(vector<vector<int>>& isInfected) {
        
    }
};