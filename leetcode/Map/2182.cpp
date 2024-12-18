#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> freq;
        for (auto it : s) {
            freq[it]++;
        }
        string res;
        while (!freq.empty()) {
            auto top = freq.begin();
            char currch = top->first;
            int count=min(repeatLimit,top->second);
            res.append(count, currch);
            top->second -= count;
            if (top->second == 0) {
                freq.erase(top);
            } else {
                if (freq.size()>1) {
                    auto it = next(freq.begin());
                    char nextchar=it->first;
                    res.push_back(nextchar);
                    if (--it->second == 0) {
                        freq.erase(it);
                    }
                } else{
                    break;
                }
            }
        }
        return res;
    }
};