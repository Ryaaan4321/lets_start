#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank;
    vector<int>parent;
    vector<int>sz;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            sz[i]=1;
        }
    }
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
            
        }
    };
    void unionbysize(int u,int v){
        int ulp_v=findparent(v);
        int ulp_u=findparent(u);
        if(ulp_u==ulp_v)return;
        if(sz[ulp_u]>sz[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(sz[ulp_v]>sz[ulp_u]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_v]=ulp_u;
            sz[ulp_u]+=sz[ulp_v];
        }
    }
};
class Solution
{
    public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjnode}});
            }
        }
        int mstwt=0;
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        for(auto it:edges){
            int wt=it.first;
            int node=it.second.first;
            int adjnode=it.second.second;
            
            if(ds.findparent(node)!=ds.findparent(adjnode)){
                mstwt+=wt;
                ds.unionbyrank(node,adjnode);
            }
        }
        return mstwt;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }
    return 0;
}
