#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a, int k) {
        int mx_len=1,ans=0,n=a.size();
        for(int i=1;i<=n-1+k-1;i++){
            if(a[i]!=a[(i-1+n)%n]){
                mx_len++;
            }else{
                mx_len=1;
            }
            if(mx_len>=k){
                ans++;
            }
        }
        return ans;
    }
};