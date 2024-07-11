#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                ans+=s[i]-48;
            }else{
                ans-=s[i]-48;
            }
        }
        return ans;
    }
};