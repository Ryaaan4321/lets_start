#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool dfs(int u,vector<int> adj[],vector<int> &vis,vector<int> &pathvis){
         vis[u]=1;
         pathvis[u]=1;
         for(auto &v:adj[u]){
            if(!vis[v]){
                if(dfs(v,adj,vis,pathvis)==true){
                    return 1;
                }
            }else if(pathvis[v]==1){
                return 1;
            }
        }
        pathvis[u]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==1){
                    return 1;
                }
            }
        }
        return 0;
    }
};