#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n=a.size();
        int m=1;
        for(int i=1;i<n;i++){
            int c=1;
            for(int j=i-1;j>=0;j--){
                if(a[j+1]>a[j]){
                    c++;
                }else{
                    break;
                }
            }
            m=max(m,c);
        }
        
        for(int i=1;i<n;i++){
            int c=1;
            for(int j=i-1;j>=0;j--){
                if(a[j+1]<a[j]){
                    c++;
                }else{
                    break;
                }
            }
            m=max(m,c);
        }
        return m;
        
    }
};

