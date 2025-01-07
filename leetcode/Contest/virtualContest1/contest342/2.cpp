#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int sumOfMultiples(int n) {
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            if((i%3==0) || (i%5==0) || (i%7==0)){
                mp[i]++;
            }
        }
        int sm=0;
        for(auto &it:mp){
            // cout<<it.first <<"it first"<<endl;
           sm+=it.first;
        }
        return sm;
    }
};