#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {

        unordered_map<char, int> indexS, indexT;
        for (int i = 0; i < s.length(); ++i) {
            indexS[s[i]] = i;
        }

        for (int i = 0; i < t.length(); ++i) {
            indexT[t[i]] = i;
        }

        int difference = 0;

        for (auto it = indexS.begin(); it != indexS.end(); ++it) {
            char ch = it->first;
            difference += abs(indexS[ch] - indexT[ch]);
        }

        return difference;
    }
};