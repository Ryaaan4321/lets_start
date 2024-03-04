#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    string lastNonEmptyString(string s)
    {
        unordered_map<char, int> freq;
        int max_freq = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            max_freq = max(max_freq, freq[s[i]]++);
        }
        string ans = "";
        unordered_map<char, int> curr;
        for (int i = 0; i < s.length(); ++i)
        {
            curr[s[i]]++;

            if (curr[s[i]] == freq[s[i]])
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};