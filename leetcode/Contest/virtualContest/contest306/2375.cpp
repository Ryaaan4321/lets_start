#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isvalid(vector<char> &v,string pattern){
        for(int i=0;i<pattern.size();i++){
            if(pattern[i]=='I' && v[i+1]>v[i]){
                continue;
            }
            if(pattern[i]=='D' && v[i+1]<v[i]){
                continue;
            }
            return 0;
        }
        return 1;
    }
    string smallestNumber(string pattern) {
        vector<char> v;
        for(int i=1;i<pattern.size();i++){
            v.push_back(i+'0');
        }
        while(true){
            if(isvalid(v,pattern)){
                string ans;
                for(int i=0;i<v.size();i++){
                    ans.push_back(v[i]);
                }
                return ans;
            }
            next_permutation(v.begin(),v.end());
        }
    }
    string smallestNumber1(string pattern){
        int n=pattern.length();

        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=i+1;
        }
        for(int i=0;i<n;i++){
            int start=i;
            while (i<n && pattern[i]==pattern[start])
            {
                i++;
                /* code */
            }
            i--;
            if(pattern[start]=='D'){
                reverse(ans.begin()+start,ans.begin()+i+2);
            }
        }
        string str="";
        for(auto i:ans){
            str+=to_string(i);
        }
        return str;
    }
};