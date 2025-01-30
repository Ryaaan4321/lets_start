#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++){
            string str=details[i];
             int age=stoi(str.substr(11,2));
             if(age>60)cnt++;  
        }
        return cnt;
    }
};