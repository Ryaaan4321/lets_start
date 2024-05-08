#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int V,int m,vector<vector<int>> prerequisite){
        vector<int> adj[V];
        for(auto &it:prerequisite){
            adj[it[1]].push_back(it[0]);
        }
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto &it:adj[V]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};