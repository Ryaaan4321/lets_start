#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        deque<pair<int, int>> dq;
        int n = a.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (!dq.empty() && dq.back().second <= i - k)
                    dq.pop_back();
            }
            while (!dq.empty() && dq.front().first+1 != a[i])
                dq.pop_back();
            dq.push_front({a[i], i});
            if (i >= k - 1) {
                ans.push_back(dq.size() == k ? dq.front().first : -1);
            }
        }
        return ans;
    }
};