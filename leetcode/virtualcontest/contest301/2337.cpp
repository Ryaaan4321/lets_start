#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
    bool canChange(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        if (n != m)
        {
            return 0;
        }
        while (i != n && j != m)
        {
            while (i < n && s[i] == '_')
                i++;
            while (j < m && t[j] == '_')
                j++;

            if (s[i] != t[j])
                return 0;
            if (s[i] == 'R' && i > j)
                return 0; /*{s = "_R  and t = "R_*/
            if (s[i] == 'L' && i < j)
                return 0; /*{s="L_" t="_L"}*/
            i++;
            j++;
        }
        return i == n && j == m;
    }
};