#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();int ans=0;
        int r=0;int l=0;int mxlen=0;
        int hash[26]={0};
        while(r<n){
            hash[s[r]-'A']++;
            mxlen=max(mxlen,hash[s[r]-'A']);
            if((r-l+1)-mxlen>k){
                hash[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};