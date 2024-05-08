#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution{
    public:
    vector<int> dijkstra(int v,vector<vector<int>>adj[],int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(v);
        for(int i=0;i<v;i++){
            distance[i]=1e9;
        }
        distance[src]=0;
        pq.push({src,0});
        while (!pq.empty())
        {
            pair<int,int> temp=pq.top();
            int node=temp.first;
            int wt=temp.second;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it[0];
                int dist=it[1];
                if(wt+dist<distance[adjnode]){
                    distance[adjnode]=wt+dist;
                    pq.push({adjnode,distance[adjnode]});
                }
            }
        }
        return distance;
    }
    
};