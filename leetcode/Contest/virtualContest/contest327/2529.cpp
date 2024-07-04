#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& a) {
        int n=a.size();
        int po=0;
        int ne=0;
        for(int i=0;i<n;i++){
            if(a[i]>0){
                po++;
            }
            if(a[i]<0){
                ne++;
            }
        }
        return max(po,ne);
    }
};