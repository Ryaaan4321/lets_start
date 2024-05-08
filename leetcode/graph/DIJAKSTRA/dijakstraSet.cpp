#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>distance(V);
        for(int i=0;i<V;i++){
            distance[i]=1e9;
        }
        distance[S]=0;
        st.insert({S,0});
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.first;
            int wt=it.second;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjnode=it[0];
                int dist=it[1];
                if(dist+wt<distance[adjnode]){
                    
                    if(distance[adjnode]!=1e9){
                        st.erase({adjnode,distance[adjnode]});
                        
                    }
                    distance[adjnode]=dist+wt;
                    st.insert({adjnode,distance[adjnode]});
                }
            }
        }
        return distance;
        
    }
};
