#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    int maxScore(vector<int>& a) {
        int n=a.size();
        sort(a.rbegin(),a.rend());
        vector<int> pref(n+1);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+a[i-1];
        }
        int ans=0;
        for(int i=0;i<pref.size();i++){
           if(pref[i]>0){
            ans++;
           }
        }
        return ans;
    }
};