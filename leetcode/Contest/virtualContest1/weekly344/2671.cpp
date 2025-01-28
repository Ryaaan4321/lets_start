#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class FrequencyTracker {
public:
    // (1108/1118)
    map<int,int>mp;
    FrequencyTracker() {
       
    }
    
    void add(int number) {
       mp[number]++;
    }
    
    void deleteOne(int number) {
       if(mp.find(number)!=mp.end()){
        mp[number]--;
       }
    }
    bool hasFrequency(int frequency) {
       for(auto it:mp){
        if(it.second==frequency){
            return true;
        }
       }
       return false;
    }
};