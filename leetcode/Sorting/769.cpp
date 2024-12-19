#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int cnt = 0;
        int n = a.size();
        int diff = 0;
        for (int i = 0; i < n; i++) {
            diff += a[i] - i;
            cnt += (diff == 0);
        }
        return cnt;
    }
};