#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        int n=s.length();
        while (i<n)
        {
          string t="";
          while (i<n && s[i]!=' ')
          {
            t+=s[i];
            i++;
          }
          while (i<n && s[i]==' ')
          {
            i++;
          }
          while (!t.empty())
          {
            if(ans.empty()){
                ans+=t;
            }else{
                ans=ans+' '+t;
            }
          }
          
        }
        return ans;
        
    }
};