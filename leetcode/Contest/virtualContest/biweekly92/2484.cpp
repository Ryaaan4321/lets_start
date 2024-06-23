#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int fuccc(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ta = 0;
        int nt = 0;
        if (s[i] == t[j] || t[j] == '*') {
            ta = fuccc(i + 1, j + 1, s, t, dp);
        }
        nt = fuccc(i + 1, j, s, t, dp);
        dp[i][j] = nt % mod + ta % mod;
        return dp[i][j] % mod;
    }
    int countPalindromes(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        string t;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                char x = i + '0';
                char y = j + '0';
                t += x;
                t += y;
                t += '*';
                t += y;
                t += x;
                ans = (ans % mod + fuccc(0, 0, s, t, dp) % mod) % mod;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < 5; l++) {
                        dp[k][l] = -1;
                    }
                }
                t.clear();
            }
        }
        return ans % mod;
    }
};