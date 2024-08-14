#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int no, int nz, int nneg, int k) {
        priority_queue<int>pq;
        for(int i=1;i<=no;i++){
            pq.push(1);
        }
        for(int i=1;i<=nz;i++){
            pq.push(0);
        }
        for(int i=1;i<=nneg;i++){
            pq.push(-1);
        }
        int sm=0;
        while(k--){
          sm+=pq.top();
          pq.pop();
        }
        return sm;
    }
};