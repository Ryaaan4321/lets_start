#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = 0;
        }
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= m; col++)
            {
                if (s1[row - 1] == s2[col - 1])
                {
                    dp[row][col] = 1 + dp[row - 1][col - 1];
                }
                else
                {
                    dp[row][col] = 0 + max(dp[row - 1][col], dp[row][col - 1]);
                }
            }
        }
        int len = dp[n][m];
        int i = n;
        int j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }
        while (j>0)
        {
            ans+=s2[j-1];
            j--;
           
        }while (i>0)
        {
            ans+=s1[i-1];
            i--;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};