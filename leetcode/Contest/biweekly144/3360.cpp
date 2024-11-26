#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>

class Solution
{
public:
    int check(int n)
    {
        int c = 0;
        int num = 10;
        n = n - num;
        if (n < 0)
        {
            return c;
        }
        while (n >= 0)
        {
            n = n - (num - 1);
            num = num - 1;
            c++;
        }
        return c;
    }
    bool canAliceWin(int n)
    {
        if (n < 10)
        {
            return 0;
        }
        return check(n) & 1 ? 1 : 0;
    }
};

// 1510