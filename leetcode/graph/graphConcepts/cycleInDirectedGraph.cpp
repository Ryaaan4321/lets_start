#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
class Solution {
  public:
    bool dfs(int node,vector<int> adj[],int vis[],int pathvis[],int check[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,check)==1){
                    return 1;
                }
                    
            }else if(pathvis[it]==1){
                return 1;
            }
        }
        pathvis[node]=0;
        check[node]=1;
        return 0;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int check[V]={0};
        int pathvis[V]={0};
        int vis[V]={0};
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
            
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> outdegree(n, 0);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                mp[it].push_back(i);
            }
            outdegree[i] = adj[i].size();
        }
        vector<int> ans;
        vector<int> visited(n, 0);
        while (1) {
            bool flag = 0;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && outdegree[i] == 0) {
                    ans.push_back(i);
                    visited[i]=1;
                    flag = 1;
                    for (auto it : mp[i])
                        outdegree[it]--;
                }
            }
            if (!flag) {
                break;
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}
