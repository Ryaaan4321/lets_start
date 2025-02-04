#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        vector<int>freq;
        for(char ch:s){
            freq[ch-'0']++;
        }
        string ans="";
        for(int i=0;i<s.length()-1;i++){
            char a=s[i];char b=s[i+1];
            if(a!=b && freq[a-'0']==a-'0' && freq[b-'0']==b-'0'){
                ans+=a;
                ans+=b;
            }
        }
        return ans;

    }
};