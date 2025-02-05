#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>space(1,startTime[0]);
        for(int i=1;i<startTime.size();i++){
            space.push_back(startTime[i]-endTime[i-1]);    
        }
        space.push_back(eventTime-endTime.back());
        int curr=0;int mxsum=0;
        for(int i=0;i<space.size();i++){
          curr+=space[i]-((i>=k+1)?space[i-(k+1)]:0);
          mxsum=max(curr,mxsum);
        }
        return mxsum;
    }
};