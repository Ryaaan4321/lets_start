#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
/*another interval question -  452*/
class Solution
{
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int xlo = max(bottomLeft[i][0], bottomLeft[j][0]);
                int xhi = min(topRight[i][0], topRight[j][0]);

                int ylo = max(bottomLeft[i][1], bottomLeft[j][1]);
                int yhi = min(topRight[i][1], topRight[j][1]);

                int xlen = max(xhi - xlo, 0);
                int ylen = max(yhi - ylo, 0);

                long long dim = min(xlen, ylen);

                ans = max(ans, dim * dim);
            }
        }
        return ans;
    }
};