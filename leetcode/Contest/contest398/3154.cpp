#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


#define ll long long

class Solution {
public:
    int k;
    vector<ll> power;
    ll dp[50][50][2];

    ll fucc(int i, int jump, bool flag) {
        if (i > k + 1) {
            return 0;
        }
        if (dp[i][jump][flag] != -1) {
            return dp[i][jump][flag];
        }
        ll ways = 0;
        if (i == k) {
            return 1;
        }
        if (flag == 1) {
            ways += fucc(i - 1, jump, 0);
        }
        if (i + power[jump] <= k + 1) { 
            ways += fucc(i + power[jump], jump + 1, 1);
        }
        return dp[i][jump][flag] = ways;
    }

    int waysToReachStair(int k) {
        this->k = k;
        power.resize(33);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 33; i++) {
            power[i] = pow(2, i);
        }
        ll ans = fucc(1, 1, 1);
        return static_cast<int>(ans);
    }
};
