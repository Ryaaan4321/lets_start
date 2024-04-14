#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

/*study material - https://web.stanford.edu/class/cs124/lec/med.pdf*/

class Solution
{
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return j + 1;
        }
        if (j < 0)
        {
            return i + 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j])
        {
            return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2, dp);
        }
        /*insert operation = f(i, j - 1, s1, s2, dp)));*/
        /*if they match = 0 + f(i - 1, j - 1, s1, s2, dp)*/
        /*delete operation = f(i - 1, j, s1, s2, dp)*/
        else
        {
            return dp[i][j] = 1 + min(f(i - 1, j - 1, s1, s2, dp), min(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp)));
        }
    }
    int minDistance(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s1, s2, dp);
    }
};