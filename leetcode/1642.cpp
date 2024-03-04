#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solve(int idx, vector<int> &heights, int bricks, int ladder)
    {
        int n = heights.size();
        if (idx >= n - 1)
        {
            return 0;
        }
        if (heights[idx + 1] < heights[idx])
        {
            return 1 + solve(idx + 1, heights, bricks, ladder);
        }
        else
        {
            int byBrick = 0;
            int byLadder = 0;
            int diff = heights[idx + 1] - heights[idx];
            if (bricks >= diff)
            {
                byBrick += 1 + solve(idx + 1, heights, bricks - diff, ladder);
            }
            if (ladder > 0)
            {
                byLadder += 1 + solve(idx + 1, heights, bricks, ladder - 1);
            }
            return max(byBrick, byLadder);
        }
        return -1;
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        return solve(0, heights, bricks, ladders);
    }
};