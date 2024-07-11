#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }
        sort(vp.rbegin(), vp.rend());
        priority_queue<int, vector<int>, greater<int>> minh;
        ll currsum = 0;
        for (int i = 0; i < k - 1; i++) {
            minh.push(vp[i].second);
            currsum += vp[i].second;
        }
        ll ans = 0;
        for (int i = k - 1; i < n; i++) {
            currsum += vp[i].second;
            ans = max(ans, currsum * vp[i].first);
            if (minh.size() > 0 && minh.top() < vp[i].second) {
                currsum -= minh.top();
                minh.pop();
                minh.push(vp[i].second);
            } else {
                currsum -= vp[i].second;
            }
        }
        return ans;
    }
};