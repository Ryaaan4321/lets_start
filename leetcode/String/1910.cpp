#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string res="";
            int len=part.length();
            for(char ch:s){
                res.push_back(ch);
                if(res.size()>=len && res.substr(res.size()-len)==part){
                    res.erase(res.size()-len);
                }
            }
            return res;
        }
    };