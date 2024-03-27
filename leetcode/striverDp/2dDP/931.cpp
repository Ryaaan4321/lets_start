#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int n;
    int m;
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> dp)
    {
        if (j < 0 || j >= n)
        {
            return -1e9;
        }
        if(i==0){
            return matrix[0][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int leftDi = matrix[i][j] + solve(i + 1, j - 1, matrix, dp);
        int rightDi = matrix[i][j] + solve(i + 1, j, matrix, dp);
        int onest = matrix[i][j] + solve(i + 1, j + 1, matrix, dp);

        return dp[i][j] = min(leftDi, min(rightDi, onest));
    };
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, matrix, dp);
    }
};