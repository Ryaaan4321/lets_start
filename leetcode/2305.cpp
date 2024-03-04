#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution {
public:
    
    int result = INT_MAX;
    int n;
    
    void solve(int idx, vector<int>& cookies, vector<int>& children, int k) {
        if(idx == cookies.size()) {
            
            int ans = *max_element(begin(children), end(children));
            result = min(result, ans);
            return;
        }
        
        int candy = cookies[idx];
        for(int i = 0; i<k; i++) {
            children[i] += candy;
            
            solve(idx+1, cookies, children, k);
            
            children[i] -= candy;
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k);
        solve(0, cookies, children, k);
        
        return result;
    }
};