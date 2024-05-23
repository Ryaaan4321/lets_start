#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

/*you gotta be almost insane to your craft - sir mc-gregor*/

class Solution {
public:
    vector<int> findArray(vector<int>& a) {
        int n=a.size();
        for(int i=n-1;i>0;i--){
            a[i]=a[i]^a[i-1];
        }
        return a;
    }
};