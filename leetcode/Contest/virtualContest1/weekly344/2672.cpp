#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int cnt = 0;
        int m = queries.size();
        vector<int> ans;
        vector<int> colors(n, 0);
        for (int i = 0; i < m; i++) {
            int idx = queries[i][0];
            int newcol = queries[i][1];
            int leftidx = (idx - 1 < 0 ? 0 : colors[idx - 1]);
            int rightidx = (idx + 1 == n ? 0 : colors[idx + 1]);
            if (colors[idx] != 0 && leftidx == colors[idx])
                cnt--;
            if (colors[idx] != 0 && rightidx == colors[idx])
                cnt--;
            colors[idx] = newcol;
            if (leftidx == colors[idx])
                cnt++;
            if (rightidx == colors[idx])
                cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};