#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0){
            return 1;
        }
        for(int i=0;i<num;i++){
            int a=i;
            string str=to_string(i);
            reverse(str.begin(),str.end());
            int aa=stoi(str);
            if(a+aa==num){
                return 1;
            }
        }
        return 0;
    }
};