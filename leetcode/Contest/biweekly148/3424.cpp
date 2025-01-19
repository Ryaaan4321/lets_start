#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long cost1=0;long long cost2=k;
        int n=arr.size();
        for(int i=0;i<n;i++){
            cost1+=abs(arr[i]-brr[i]);
        }
        sort(begin(arr),end(arr));
        sort(begin(brr),end(brr));
        for(int i=0;i<n;i++){
            cost2+=abs(arr[i]-brr[i]);
        }
        return min(cost1,cost2);
    }
};