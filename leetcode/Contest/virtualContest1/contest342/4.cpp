#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int time=(arrivalTime+delayedTime);
        int final=time%24;
        return final;
        
    }
};