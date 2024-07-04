#include<bits/stdc++.h>
#include<algorithm>

using namespace std;


class Solution {
public:
    int xorBeauty(vector<int>& a) {
        int ans=0;
        for(auto it:a){
            ans^=it;
        }
        return ans;
    }
};

/*

l=2909
w=3968
h=3272
m=727
wa = heavy
output =  both

*/