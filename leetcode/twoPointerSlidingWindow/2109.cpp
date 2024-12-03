#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int i = 0;
        int j = 0;
        int n = s.length();
        int m = spaces.size();
        string res = "";
        while (i < n)
        {
            if (j < m && i == spaces[j])
            {
                res += " ";
                j++;
            }
            res += s[i];
            i++;
        }
        return res;
    }
};