#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>ar;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                ar.push_back(i);
            }
            if(ar.size()>2)return 0;
        }
        if(ar.size()==0)return true;
        if(ar.size()==2){
            int st=ar[0];int e=ar[1];
            return s1[st]==s2[e] && s1[e]==s2[st];
        }
        return false;

    }
};