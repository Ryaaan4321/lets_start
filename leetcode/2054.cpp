#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events),end(events));
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(const auto &event:events){
            int start=event[0];
            int end=event[1];
            int value=event[2];
            int maxans=0;
            while(!pq.empty() && pq.top().first <start){
                maxans=max(maxans,pq.top().second);
                pq.pop();
            } 
            ans=max(ans,maxans+value);
            pq.push({end,value});
        }
        return ans;
    }
};