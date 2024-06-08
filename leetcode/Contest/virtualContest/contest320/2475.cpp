#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& a) {
        int _cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                for (int k = j + 1; k < a.size(); k++) {
                    if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k]) {
                        _cnt++;
                    }
                }
            }
        }
        return _cnt;
    }
};
