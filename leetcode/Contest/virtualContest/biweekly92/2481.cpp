#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    int numberOfCuts(int n) {
        if(n==2){
            return 1;
        }if(n==1){
            return 0;
        }
        if(n&1){
            return n;
        }else {
            return n/2;
        }
        
    }
};