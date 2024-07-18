#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


class Solution {
public:
    vector<int> leftRightDifference(vector<int> &a) {
        int n = a.size();
        vector<int> pl(n, 0); 
        vector<int> pr(n, 0); 
        
        for (int i = 1; i < n; i++) {
            pl[i] = pl[i-1] + a[i-1];
        }
        for (int i = n-2; i >= 0; i--) {
            pr[i] = pr[i+1] + a[i+1];
        }
        
        vector<int> ans(n); 
        for (int i = 0; i < n; i++) {
            ans[i] = abs(pl[i] - pr[i]);
        }
        return ans;
    }
};