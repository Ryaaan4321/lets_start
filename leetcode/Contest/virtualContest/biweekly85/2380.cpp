#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]=='0' && s[i+1]=='1'){
                    cnt++;
                }else if(s[i]=='1' && s[i+1]=='0'){
                    continue;
                }
            }
        }
        return cnt;
    }
};