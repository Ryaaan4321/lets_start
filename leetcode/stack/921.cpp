#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int _=0;
        int c=0;
        int o=0;
        for(;_<s.length();_++){
            if(s[_]=='('){
                o++;
            }
            else if(s[_]==')' && o>0){
                o--;
            }else{
                c++;
            }
        }
        return (o+c);
    }
};