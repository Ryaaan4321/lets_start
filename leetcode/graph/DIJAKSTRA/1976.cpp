#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        long long mod=long(1e9+7);
        vector<pair<long long ,long long>>adj[n];
         for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<long long>distance(n,LONG_MAX);
        vector<long long>ways(n,0);
        distance[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            pair<long long ,long long>tmp=pq.top();
            pq.pop();
            long long node=tmp.first;
            long long dist=tmp.second;
            for(auto it:adj[node]){
                long long adjnode=it.first;
                long long wt=it.second;
                if(wt+dist<distance[adjnode]){
                    distance[adjnode]=wt+dist;
                    ways[adjnode]=ways[node];
                    pq.push({adjnode, distance[adjnode]});
                }
                else if(dist+wt==distance[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};