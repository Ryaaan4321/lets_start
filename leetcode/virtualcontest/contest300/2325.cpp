#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        map<char, char> mp;
        int i = 0;
        for (auto x : key)
        {
            if (x == ' ' || mp.find(x) != mp.end())
                continue;
            mp[x] = (char)('a' + i);
            i = ++i % 26;
        }
        for (int i = 0; i < message.size(); ++i)
        {
            if (message[i] != ' ')
            {
                message[i] = mp[message[i]];
            }
        }
        return message;
    }
};