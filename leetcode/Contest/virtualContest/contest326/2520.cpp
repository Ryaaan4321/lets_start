#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool check(int n){
        bool f=1;
        if(n==1 || n==0){
            f=0;
        }
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                f=0;
                break;
            }
        }
        return (f==1?1:0);
    }
    int countDigits(int num) {
        string s=to_string(num);
        if(s.size()==1){
            return 1;
        }
        int c=1;
        set<int>st;
        for(int i=0;i<s.length();i++){
            int v=atoi(&s[i]);
            st.insert(v);
        }
        for(auto it:st){
            if(it%num==0){
                c++;
            }
        }
        return c;
    }
};

