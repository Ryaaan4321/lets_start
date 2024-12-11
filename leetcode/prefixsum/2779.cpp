#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(2 * (1e5 + 1), 0);
        for (int i = 0; i < n; i++) {
            int startrange = nums[i] - k;
            int endrange = nums[i] + k;
            if (startrange <= 0) {
                pref[0] += 1;
            } else {
                pref[startrange] += 1;
            }
            pref[endrange + 1] -= 1;
        }
        int mx = 0;
        int size = pref.size();
        for (int i = 1; i < size; i++) {
            pref[i] += pref[i - 1];
            mx = max(mx, pref[i]);
        }
        return mx;
    }
};