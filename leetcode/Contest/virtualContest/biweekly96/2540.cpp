#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
        set<int>a,b;
        for(auto it:n1){
            a.insert(it);
        }
        for(auto it:n2){
            b.insert(it);
        }
        int mn=INT_MAX;
        for(auto it:a){
            if(b.find(it)!=b.end()){
                if(mn>it){
                    mn=it;
                }
            }
        }
        return (mn==INT_MAX?-1:mn);
    }
};