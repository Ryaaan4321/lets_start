#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &counter)
    {

        for (int &it : counter)
        {
            if (it != 0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string pat)
    {
        int n = txt.size();
        vector<int> counter(26, 0);
        for (int i = 0; i < n; i++)
        {
            char ch = pat[i];
            counter[ch-'a']++;
        }
        
    }
};