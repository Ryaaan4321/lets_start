#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n<2)return 1;
        vector<vector<int>>gr(n);
        vector<int>indegree(n);
        vector<long long>nodevalues(begin(values),end(values));
        for(auto &x:edges){
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            indegree[node]--;
            long long value=(nodevalues[node]%k==0?0:nodevalues[node]);
            if(value==0){
                ans++;
            }
            for(int &neb:gr[node]){
                if(indegree[neb]>0){
                    indegree[neb]--;
                    nodevalues[neb]+=value;
                    if(indegree[neb]==1){
                        q.push(neb);
                    }
                }
            }
        }
        return ans;

    }
};