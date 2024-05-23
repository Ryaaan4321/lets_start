#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
            string tmp=to_string(it);
            reverse(tmp.begin(),tmp.end());
            int tmp1=stoi(tmp);
            st.insert(tmp1);
            st.insert(tmp1);
        }
        return st.size();
    }
};