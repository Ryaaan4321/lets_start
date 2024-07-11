#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int s1=0;
        int t1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                s1++;
            }
            if(t[i]=='1'){
                t1++;
            }
        }
        if(s1>0 && t1==0){
            return 0;
        }
        if(t1>0 && s1==0){
            return 0;
        }
        return 1;
    }
};