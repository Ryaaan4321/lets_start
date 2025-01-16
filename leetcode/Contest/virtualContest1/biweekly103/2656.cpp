#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long score=0;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            score+=node;
            pq.push(node+1);
        }
        return score;
    }
};