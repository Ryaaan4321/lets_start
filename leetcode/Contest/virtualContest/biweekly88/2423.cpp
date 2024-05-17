#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> fq(26, 0);
        for (auto it : word) {
            fq[it - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            vector<int> t=fq;
            if (fq[i] <= 0) {
                continue;
            }
            t[i]--;
            set<int>st;
            for (auto it : t) {
                if (it > 0) {
                    st.insert(it);
                }
            }
            if (st.size() == 1) {
                return 1;
            }
        }
        return 0;
    }
};