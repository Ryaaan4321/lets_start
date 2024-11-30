#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree;
        unordered_map<int,int>outdegree;
        for(auto &edges:grid){
            int u=edges[0];
            int v=edges[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int startnode=grid[0][0];int endnode=0;
        for(auto &it:adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1)
            {
                startnode=node;
                break;
            }
        }
        stack<int>st;
        vector<int>path;
        st.push(startnode);
        while(!st.empty()){
            int node=st.top();
            if(!adj[node].empty()){
                int nei=adj[node].back();
                adj[node].pop_back();
                st.push(nei);
            }else{
                path.push_back(node);
                st.pop();
            }
        }
        reverse(begin(path),end(path));
        vector<vector<int>>ans;
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};