#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{

    string findLCS(int n, int m, string &text1, string &text2)
    {
        int t[1001][1001];

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = std::max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;
        string str2 = "";

        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                str2 += text1[i - 1];
                i--;
                j--;
            }
            else
            {
                if (t[i][j - 1] > t[i - 1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }

        reverse(str2.begin(), str2.end());

        return str2;
    }
};