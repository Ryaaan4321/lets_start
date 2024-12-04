#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i=0;int j=0;
        int n=s.length();int m=t.length();
        while(i<n && j<m){
            if(s[i]==t[j] or s[i]+1==t[j]){
                i++;j++;
            }
            else if(s[i]=='z' && t[j]=='a'){
                i++;j++;
            }else 
            i++;
        }
        return j==t.length()?1:0;
    }
};