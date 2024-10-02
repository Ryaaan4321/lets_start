#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
 
class Solution {
public:
    long long maximumTotalSum(vector<int>& a) {
        sort(begin(a),end(a));
        int n=a.size();
        long long ans=0;
        int prev=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(a[i]<prev){
                ans+=a[i],prev=a[i];
            }else{
                ans+=prev-1,prev=prev-1;
            }
            if(prev==0){
                return -1;
            }
        }
        return ans;
    }
};