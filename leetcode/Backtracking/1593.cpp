#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    int fucc1(int idx,const string &s,set<string>&st){
        if(idx==s.size()){
            return 0;
        }
        int cnt=0;
        for(int i=idx+1;i<=s.size();i++){
            string substr=s.substr(i,i-idx);
            if(st.find(substr)==st.end()){
                st.insert(substr);
                cnt=max(cnt,1+fucc1(i,s,st));
                st.erase(substr);
            }
        }
        return cnt;
    }
    int cnt=1;
    bool ispresent(vector<string>&a,string s){
        return std::find(begin(a),a.end(),s)!=a.end();
    }
    void fucc(int idx,const string&s,vector<string>&a){
        if(idx==s.size())
        {
            cnt=max(cnt,(int)a.size());
            return;
        }
        for(int i=idx+1;i<=s.length();i++){
            string sub=s.substr(i,i-idx);
            if(ispresent(a,s)){
                continue;
            }
            a.push_back(sub);
            fucc(i,s,a);
            a.pop_back();
        }
    }
    int maxUniqueSplit(string s) {
        set<string>st;
        return fucc1(0,s,st);
    }
};

