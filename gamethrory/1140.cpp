#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
// https://leetcode.com/problems/stone-game-ii/
class Solution
{
public:
    int n;
    int dp[2][101][101];
    /*defining the states accordint to the changes we are doing in our recursion
    first dp[2] is telling about the state of the either the alice or bob if it is 1 then alice otherwise it s bob
    then size of the array is 100 than 101 and becuase we are going to traverse in the array and the value of the M
    will also range so thats why
    */

    int solve(vector<int> &piles, int person, int i, int M)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[person][i][M] != -1)
        {
            return dp[person][i][M];
        }
        int result = (person == 1) ? -1 : INT_MAX;//takes value accordingly if it is 1 then its alice so takes -1 becuase we want to take the max value
        // and if it is bob then INT_MAX than intmax because we want to have min value for it
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++)
        {
            stones += piles[i + x - 1];

            if (person == 1)
            {
                //if it is alice than taking max out of it
                result = max(result, stones + solve(piles, 0, i + x, max(M, x)));
            }
            else
            {
                //if it is bob then taking min out of it
                result = min(result, solve(piles, 1, i + x, max(M, x)));
            }
        }
        return dp[person][i][M] = result;
    }
    int stoneGameII(vector<int> &piles)
    {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return solve(piles, 1, 0, 1);
    }
};