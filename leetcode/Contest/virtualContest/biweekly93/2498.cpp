#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxJump(vector<int>& a) {
        int cost=a[1]-a[0];
        for(int i=2;i<a.size();i++){
            cost=max(cost,a[i]-a[i-2]);
        }
        return cost;
    }
};