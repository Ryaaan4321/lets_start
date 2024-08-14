#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;
class Solution {
public:
    long long findScore(vector<int>& a) {
        ll ans=0;
        int n=a.size(),c=0;
        map<int,bool>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({a[i],i});
        }
        while(n--){
            auto ele=pq.top();
            pq.pop();
            int v=ele.first;
            int ind=ele.second;
            if(mp.find(ind)==mp.end()){
                ans+=v;
                mp[ind]=1;
                mp[ind-1]=1;
                mp[ind+1]=1;
            }
        }
        return ans;
    }
};