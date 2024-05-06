#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> shortedPath(vector<vector<int>> edges, int N, int M ,int src)
    {
        queue<int>q;
        vector<int>dis(N);
        for(int i=0;i<N;i++)dis[i]=1e9;
        vector<int> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        q.push(src);
        dis[src]=0;
        while (!q.empty())
        {
            auto node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dis[it]+1<dis[node]){
                    dis[node]=1+dis[it];
                    q.push(it);
                }
            }
        }
        vector<int> ans(N,-1);
        for(int i=0;i<N;i++){
            if(dis[i]!=1e9){
                ans[i]=dis[i];
            }
        }
        return ans;
    }
};