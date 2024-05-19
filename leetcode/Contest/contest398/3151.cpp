#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

/*you gotta be almost insane to your craft - mcGregor*/

class Solution {
public:
    bool isArraySpecial(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++){
            if(i+1<=n &&  a[i]&1 && a[i+1]&1){
                return false;
            }
            if(i+1<=n && a[i]%2==0 && a[i+1]%2==0){
                return false;
            }
        }
        return true;
    }
    bool isArraySpecial(vector<int>& a){
        for(int i=1;i<a.size();i++){
            if((a[i]^a[i-1])&1==0){
                return 0;
            }
        }
        return 1;
    }
};

