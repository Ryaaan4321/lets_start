#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int sm = 0;
        for (int i = 0; i < n; i++) {
            sm += a[i];
            sm %= k;
            if(sm<0){
                sm+=k;
            }
            if (mp.find(sm) != mp.end()) {
                cnt+=mp[sm];
                mp[sm]+=1;
            } else {
                mp[sm] = 1;
            }
        }
        return cnt;
    }
};