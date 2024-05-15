#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution{
    public:
    int longestContinousSubstring(string s){
        int cnt=1;
        int n=s.length();
        for(int i=0;i<n;i++){
            int cur=1;
            while(i<n-1 && s[i+1]-s[i]==1){
                cur++;i++;
            }
            cnt=max(cnt,cur);
        }
        return cnt;
    }
};