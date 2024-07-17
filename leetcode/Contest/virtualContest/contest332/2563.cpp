#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& a, int l_b, int u_b) {
        long long cnt=0;
        int n=a.size();
        sort(a.begin(),a.end());
        for (int i = 0; i < n; ++i) {
            int low = lower_bound(a.begin() + i + 1, a.end(), l_b - a[i]) - a.begin();
            int high = upper_bound(a.begin() + i + 1, a.end(), u_b - a[i]) - a.begin() - 1;
            if (low <= high) {
                cnt += (high - low + 1);
            }
        }

        return cnt;
    }
};