#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
/*
 Company Tags                 : Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal,
                                   D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, nearbuy, Nagarro, BrowserStack
    Frequency                    : 80%
    Leetcode Qn Link             : https://leetcode.com/problems/spiral-matrix/
    Similar GfG Link             : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, top = 0, down = n - 1, right = m - 1;
        int id = 0;

        while (top <= down && left <= right)
        {
            if (id == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if (id == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }

            if (id == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if (id == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            id = (id + 1) % 4;
        }
        return ans;
    }
};