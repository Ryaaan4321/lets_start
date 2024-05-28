#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int diff(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
            }
        }
        return cnt;
    };
    vector<string> twoEditWords(vector<string>& que, vector<string>& dict) {
        vector<string> ans;
        for (auto q : que) {
            int mn = INT_MAX;
            for (auto d : dict) {
                mn = min(mn, diff(q, d));
            }
            if (mn <= 2) {
                ans.push_back(q);
            }
        }
        return ans;
    }
};