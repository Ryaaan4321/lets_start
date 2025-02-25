#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    void fucc(int node, int& nodecount, int& edegecount,
              map<int, vector<int>> graph, vector<bool>& vis) {
        vis[node] = true;
        nodecount += 1;
        edegecount += graph[node].size();
        for (auto nei : graph[node]) {
            if (!vis[nei]) {
                fucc(nei, nodecount, edegecount, graph, vis);
            }
        }
    }
    bool fuccc(int node, map<int,vector<int>>graph,vector<bool>&vis){
        vis[node]=true;
        int nodecount=0;
        int edgecount=0;
        stack<int>st;st.push(node);
        while (!st.empty())
        {
            auto elm=st.top();
            st.pop();
            nodecount++;
            edgecount+=graph[elm].size();
            for(auto &nei:graph[elm]){
                if(!vis[nei]){
                    st.push(nei);
                    vis[nei]=true;
                }
            }
        }
        return (nodecount*(nodecount-1)==edgecount);
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        vector<bool> vis(n);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int cnt = 0;
        for (int node = 0; node < n; node++) {
            int nodecount = 0;
            int edgecount = 0;
            if (!vis[node]) {
                fucc(node, nodecount, edgecount, graph, vis);
                if (nodecount * (nodecount - 1) == edgecount)cnt++;
            }
        }
        return cnt;
    }
    vector<int>parent,edegcount,nodecount;
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return findparent(parent[node]);
    };
    void union_nodes(int a,int b){
        int pa=findparent(a);
        int pb=findparent(b);
        edegcount[pa]+=1;
        if(pa!=pb){
            parent[pb]=pa;
            edegcount[pa]+=edegcount[pb];
            nodecount[pa]+=nodecount[pb];
        }
    }
    int countCompleteComponennt(int n,vector<vector<int>>&edges){
       int ans=0;
       parent.assign(n,-1);
       edegcount.assign(n,0);
       nodecount.assign(n,1);
       for(auto edge:edges){
        union_nodes(edge[0],edge[1]);
       }
       int ans=0;
       for(int i=0;i<n;i++){
        if(nodecount[i] && parent[i]==-1 && (nodecount[i]-1)/2==edegcount[i])ans++;
       }
       return ans;
    }

};