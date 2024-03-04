// #include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>
// /*And one day evrything got changed and he became his own companion;*/

// using namespace std;

// class Solution
// {
// public:
//     int dp[1001][1001];
//     int check(string &s, string &t, int i, int j)
//     {
//         int n = s.size();
//         int m = t.size();

//         if (i >= n || j >= m)
//         {
//             return 0;
//         }
//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         if (s[i] == t[i])
//         {
//             dp[i][j] = 1 + dp[i + 1][j + 1];
//         }
//         else
//         {
//             dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
//         }
//         return dp[i][j];
//     }
//     bool isSubsequence(string s, string t)
//     {
//         memset(dp, -1, sizeof(dp));
//         int n = s.length();
//         int m = t.length();
//         int ans=check()
//     }
// };