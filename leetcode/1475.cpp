#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = a[i];
            for (int j = i + 1; j < n; j++) {
                if (a[i] >= a[j]) {
                    ans[i] = a[i] - a[j];
                    break;
                }
            }
        }
        return ans;
    }
};