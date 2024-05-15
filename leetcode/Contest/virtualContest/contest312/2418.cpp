#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& str, vector<int>& a) {
        int n = a.size();
        pair<int, string> p[n];
        for (int i = 0; i < n; i++) {
            p[i].first = a[i];
            p[i].second = str[i];
        }
        sort(p, p + n,[](const pair<int, string>& a, const pair<int, string>& b) -> bool {
                return a.first > b.first;
            });
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};