#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto top=pq.top();
            pq.pop();
            int idx=top.second;
            int elm=top.first;
            nums[idx]=elm*m;
            pq.push({m*elm,idx});
        }
        return nums;
    }
};