#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& a) {
        deque<int>dq;
        sort(a.begin(),a.end());
        for(auto it:a){
            dq.push_back(it);
        }
        double ans=INT_MAX;
        while(!dq.empty()){
            int sm=dq.front();
            dq.pop_front();
            int la=dq.back();
            dq.pop_back();
            ans=min(ans,double(sm+la)/2);
        }
        return ans;
    }
};