#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        unordered_map<int, int> mp;
        int sm = 0;
        mp[0] = -1;
        for (int i = 0; i < a.size(); i++) {
            sm += a[i];
            sm %= k;
            if (mp.find(sm) != mp.end()) {
                if (i - mp[sm] > 1) {
                    return 1;
                }
            } else {
                mp[sm] = i;
            }
        }
        return 0;
    }
};
