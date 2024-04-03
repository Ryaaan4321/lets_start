#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> genrateMatrix(int n)
    {
        if (n == 0)
        {
            return {};
        }
        int m = n;
        int ans = 0;
        vector<vector<int>> matrix(m, (vector<int>(n)));

        int left = 0, top = 0, down = n - 1, right = m - 1;
        int id = 0; // tellin us the direction

        while (top <= down && left <= right)
        {
            if (id == 0) // if it ist 0 then left to right;
            {
                for (int i = left; i <= right; i++)
                {
                    matrix[top][i] = ans++;
                }
                top++;
            }
            if (id == 1) /*if it is 1 than top to down*/
            {
                for (int i = top; i <= down; i++)
                {
                    matrix[i][right] = ans++;
                }
                right--;
            }

            if (id == 2) /*if it is 2 then right to left*/
            {
                for (int i = right; i >= left; i--)
                {
                    matrix[down][i]=ans++;
                }
                down--;
            }
            if (id == 3) /* if it is 3 than down to top*/
            {
                for (int i = down; i >= top; i--)
                {
                    matrix[i][left]=ans++;
                }
                left++;
            }
            id = (id + 1) % 4;
        }
        return matrix;
    }
};