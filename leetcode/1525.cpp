#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.size();
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int cnt = 0;
        for (auto it : s)
        {
            map2[it]++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            map1[s[i]]++;
            map2[s[i]]--;

            if (map2[s[i]] == 0)
            {
                map2.erase(s[i]);
            }
            if (map1.size() == map2.size())
            {
                cnt++;
            }
        }
        return cnt;
    }
};
// aacaba
/*
map2[a,1];
map2[a,2];
map2[c,1];
map2[a,3]
map2[b,1];
map2[a,4];


map1[a,1];
map1[a,2];
map1[c,1];
map1[a,3];
map1[b,1];
map1[a,4];

map1[{a,3},{b,1},{c,1}];
map2[{a,2},{b,0},{c,1}];


*/