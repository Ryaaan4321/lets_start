#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& a, int k) {
        priority_queue<int>pq;
        for(int i=0;i<a.size();i++){
            pq.push(a[i]);
        }
        while(k--){
            int top=pq.top();
            pq.push((int)sqrt(top));
            pq.pop();
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};