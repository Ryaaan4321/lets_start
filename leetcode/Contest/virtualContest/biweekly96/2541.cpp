#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define ll long long
class Solution
{
public:
    long long minOperations(vector<int> &n1, vector<int> &n2, int k)
    {
        int n=n1.size();
        int m=n2.size();
        int i=0;
        int j=0;
        auto isequal=[&](int i,int j,vector<int>a,vector<int>&b)->bool{
            return a[i]==b[j];
            i++;
            j++;
        };
        ll ans=0;
        while(i<=n && j<=m){
            if(n1[i]==n2[j]){
                i++;
                j++;
            }
            else if(n1[i]==n2[i]+k){
                n1[i]=n1[i]-k;
                i++;
                j++;
            }else if(n1[i]-k==n2[j]){
                n1[i]=n1[i]-k;
                i++;
                j++;
            }
            ans++;
        }
        return ans;
    }
};