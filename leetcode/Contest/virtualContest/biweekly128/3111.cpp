#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<=s.length();i++){
            string str=s.substr(i,2);
            if(i+1<n){
                if(s[i]=='0' && s[i+1]=='1'){
                cnt++;
            }

            }
            
            
        }
        return cnt;
        
    }
};