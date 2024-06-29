#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define ll long long
class Solution {
public:
    ll dp[1001][1001];
    const int mod = 1e9 + 7;
    int fucc(int idx, int sm, int k, vector<int>& a) {
        if (idx == a.size()) {
            if (sm < k) {
                return 1;
            }
            return 0;
        }
        if (dp[idx][sm] != -1) {
            return dp[idx][sm];
        }
        int _t = 0;
        int _nt = 0;
        if (sm + a[idx] < k) {
            _t = fucc(idx + 1, sm + a[idx], k, a);
        }
        _nt = fucc(idx + 1, sm, k, a);

        return dp[idx][sm] = (_t + _nt) % mod;
    }
    int countPartitions(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        int tot = 0;
        for (auto it : nums) {
            tot += it;
        }
        if (tot / 2 < k) {
            return 0;
        }
        int wrong_partition = fucc(0, 0, k, nums);
        int totSubset = 1;
        for (int i = 1; i <= nums.size(); i++) {
            totSubset = (totSubset * 2) % mod;
        }
        ll res = totSubset - 2 * wrong_partition;
        if (res < 0) {
            res += mod;
        }
        return res % mod;
    }
};