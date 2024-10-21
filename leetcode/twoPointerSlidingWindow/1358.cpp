#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>mp;int cnt=0;
        int left=0;int right=0;
        int n=s.size();int len=0;
        while(right<n){
            mp[s[right]-'a']++;
            if(mp[0] && mp[1] && mp[2]){
               cnt+=n-right;
               mp[s[left]-'a']--;
               left++;
            }
            right++;
        }
        return cnt;
    }
};