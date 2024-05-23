#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int findMaxK(vector<int>& a) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<a.size();i++){
            if(a[i]>mx){
                mx=a[i];
            }
            if(a[i]<mn){
                mn=a[i];
            }
        }
        for(int i=0;i<a.size();i++){
            if(mx-mx==0){
                return mx;
            }
        }
        return -1;


        
    }
};