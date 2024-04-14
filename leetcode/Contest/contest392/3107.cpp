#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                ans += max(0, a[i] - k);
            else if (i == n / 2)
                ans += abs(a[i] - k);
            else
                ans += max(0, k - a[i]);
        }
        return ans;
    }
};