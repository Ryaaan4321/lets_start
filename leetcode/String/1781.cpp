#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int f1[26] = {0};
            for (int j = i; j < s.length(); j++) {
                f1[s[j] - 'a']++;
                int mn = INT_MAX;
                int mx = INT_MIN;
                for (int i = 0; i < 26; i++) {
                    if (f1[i] != 0) {
                        mn = min(mn, f1[i]);
                        mx = max(mx, f1[i]);
                    }
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};