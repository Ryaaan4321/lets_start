#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int  maxlength=0;int mnnode=INT_MAX;
    void dfs(int node ,int parent,int start,int end,int pathsum,vector<vector<pair<int,int>>>&graph,vector<int>&nums,unordered_map<int,int>&depthmap,vector<int>&path){
        int prevdepth=depthmap.count(nums[node])?depthmap[nums[node]]:-1;
        while(start<=prevdepth){
            pathsum-=path[start++];
            
        }
        if(pathsum> maxlength){
            maxlength=pathsum;
            mnnode=end-start+1;
        }else if(pathsum>=maxlength){
            mnnode=min(mnnode,end-start+1);
        }
        depthmap[nums[node]]=end;
        for (auto& [neighbour, weight] : graph[node]) {
           if(neighbour!=parent){
            path.push_back(weight);
            dfs(neighbour,node,start,end+1,pathsum+weight,graph,nums,depthmap,path);
            path.pop_back();
           }
        }
        depthmap[nums[node]]=prevdepth;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>>graph(n);
        for(auto &edge:edges){
            graph[edge[1]].emplace_back(edge[0],edge[2]);
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        unordered_map<int,int>depthmap;
        vector<int>path={};
        dfs(0,-1,0,0,0,graph,nums,depthmap,path);
        return {maxlength,mnnode};
    }
};