#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public: 
    static bool srt(pair<int,int>&f,pair<int,int>&s){
        return f.first-f.second >s.first-s.second;
    }
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int,int>>ar;
        for(int i=0;i<(int)reward1.size();i++){
            ar.push_back({reward1[i],reward2[i]});
        }
        sort(ar.begin(),ar.end(),srt);
        long long ans=0;
        for(int i=0;i<(int)ar.size();i++){
            if(k>0){
                ans+=ar[i].first;
                k--;
            }else{
                ans+=ar[i].second;
            }
        }
        return ans;
    }
};