#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define ll long long
class Solution
{
public:
    long long maximumPoints(vector<int> &a, int k)
    {
        int mn=*min_element(a.begin(),a.end());
        if(mn>k){
            return 0;
        }
        ll sm=0;
        for(auto it:a){
            sm+=it;
        }
        sm-=mn;
        sm+=k;
        return sm/mn;
    }
};