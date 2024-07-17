#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    bool isvalid(string s){
        if(s[0]!='a' || s[0]!='e' || s[0]!='i' || s[0]!='o'|| s[0]!='u'){
            return false;
        }
        if(s[(int)s.length()-1]!='a' || s[(int)s.length()-1]!='e' || s[(int)s.length()-1] !='i' || s[(int)s.length()-1]!='o'||s[(int)s.length()-1]!='u'){
            return false;
        }
        return true;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
    }
};