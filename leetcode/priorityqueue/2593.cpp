#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        map<int, int> mp;
        while (n--) {
            auto top = pq.top();
            pq.pop();
            int elem = top.first;
            int idx = top.second;
            if(mp.find(idx) == mp.end()) {
                ans+=elem;
                mp[idx] = 1;
                mp[idx - 1] = 1;
                mp[idx + 1] = 1;
            }
        }
        return ans;
    }
};