#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string s, string t)
    {
        int i = 0;
        int curpos = 1;
        int n = s.length();
        while (i < n)
        {
            while (i < n && s[i] == ' ')
            {
                curpos++;
                i++;
            }
            int j = 0;
            while (i < n && j < t.length() && s[i] == t[j])
            {
                i++;
                j++;
            }
            if (j == t.length())
                return curpos;
            while (i < n && s[i] != ' ')
            {
                i++;
            }
        }
        return -1;
    }
};