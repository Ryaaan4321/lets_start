#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt=0;
        int mx=min(a,b);
        for(int i=1;i<=mx;i++){
            cout<<i<<endl;
            if((a%i==0 && b%i==0)){
                cnt++;
            }
        }
        return cnt;
    }
};