#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        long long sc=0;
        while(k--){
            int val=pq.top();
            sc+=val;
            pq.pop();
            pq.push(ceil(double(val/3.0)));
        }
        return sc;
    }
};