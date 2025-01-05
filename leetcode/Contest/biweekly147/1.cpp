#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int idx=p.find('*');
        string pre=p.substr(0,idx);
        string suff=p.substr(idx+1,p.length());
        int pi=s.find(pre);
        cout<<pi<<" pi "<<endl;
        if(pi==string::npos)return 0;
        int si=s.find(suff,pi+pre.size());
        cout<<si << " si "<<endl;
        if(si==string::npos)return 0;
        return 1;
        
    }
};