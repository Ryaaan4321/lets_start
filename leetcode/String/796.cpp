#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string t) {
        vector<int>f1(26);
        vector<int>f2(26);
        for(int i=0;i<s.length();i++){
            f1[s[i]-'a']++;
        }
         for(int i=0;i<t.length();i++){
            f2[t[i]-'a']++;
        }

        bool f=1;
        for(int i=0;i<26;i++){
            if(s[i]!=t[i]){
                f=0;
                break;
            }
        }
        for(int i=0;i<26;i++){
            cout<<f1[i] << '   ' << f2[i];
            cout<<endl;
        }
        return f;
    }
};