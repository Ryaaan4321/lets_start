#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string st="";
        for(char ch:s){
            if(ch=='('){
                if(cnt>0){
                  st+=ch;
                }
                cnt++;
            }else{
                cnt--;
                if(cnt>0){
                    st+=ch;
                }
            }
        }
        return st;
    }
};