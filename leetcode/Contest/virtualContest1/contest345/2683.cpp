#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
    public:
        bool doesValidArrayExist(vector<int>& a) {
            int ans=0;
            for(int i=0;i<a.size();i++){
                ans^=a[i];
            }
            return ans==0;
        }
    };