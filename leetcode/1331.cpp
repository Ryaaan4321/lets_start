#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        sort(begin(a),end(a));
        map<int,int>mp;
        for(int i=0;i<(int)a.size();i++){
            if(mp.find(a[i])!=mp.end()){
                mp.insert({a[i],i});
            }else{
                mp[a[i]]=mp[a[i]];
            }
        }
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};