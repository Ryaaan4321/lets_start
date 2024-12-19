#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int mx=INT_MIN;
            while(!st.empty() && st.top()>arr[i]){
                mx=max(mx,st.top());
                st.pop();
            }
            if(mx==INT_MIN){
                st.push(arr[i]);
            }else{
                st.push(mx);
            }
        }
        return st.size();
    }
};