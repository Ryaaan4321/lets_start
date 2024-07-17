#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& a) {
      unordered_map<int,int>mp;
      for(auto &it:a){
        mp[it]++;
      }  
      for(int i=0;i<32;i++){
        if(!mp.count(1<<i)){
            return (1<<i);
        }
      }
      return (1<<32);
    }
};