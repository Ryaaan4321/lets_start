#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int cnt = 0;
        int mx = 0;
        int ans = 0;
        for (int it : a) {
            mx = max(mx, it);
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == mx) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};