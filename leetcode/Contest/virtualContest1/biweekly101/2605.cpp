#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int mn=INT_MAX;
        int mn1=*min_element(a.begin(),a.end());
        int mn2=*min_element(b.begin(),b.end());
        int to1=mn1*10+mn2;
        int to2=mn2*10+mn1;
        return min(to1,to2);
    }
};