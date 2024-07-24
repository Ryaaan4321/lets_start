#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    long long int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    };
    int findValidSplit(vector<int> &a)
    {
        int n = a.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;
        while (i <= ans)
        {
            j = n - 1;
            while (j > ans && gcd(a[i], a[j]) == 1)
            {
                j--;
            }
            i++;
            ans = j;
            if (ans == n - 1)
            {
                return -1;
            }
        }
        return ans;
    }
};
