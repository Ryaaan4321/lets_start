#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    // i have approached with this way bt not worked only 81 test cases passed out of 98 
    bool canArrange(vector<int> &arr, int k)
    {
        map<int,int>mp;
        for(auto &it:arr){
            mp[it]++;
        }
        bool f=0;
        for(int i=0;i<(int)arr.size();i++){
            if(mp.find(abs(k-arr[i]))==mp.end()){
              f=1;
              break;
            }
        }
        return (f==1?1:0);
    }
    bool canArrange1(vector<int>& ar, int k) {
        vector<int>f(k);
        for(int n:ar){
            int r=n%k;
            if(r<0){
                r+=k;
            }
            f[r]++;
        }
        if(f[0]%2!=0){
            return 0;
        }
        for(int i=1;i<=k/2;i++){
            if(f[i]!=f[k-i]){
                return 0;
            }
        }
        return 1;
    }
};