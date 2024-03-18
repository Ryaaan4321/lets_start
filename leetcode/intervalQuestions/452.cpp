#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/*another interval question -  3047*/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(begin(points), end(points));
        vector<int> prev = points[0];
        int cnt = 0;
        int n = points.size();
        for (int i = 1; i < n; i++)
        {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            int prevStart = prev[0];
            int prevEnd = prev[1];

            if (currStart > prevEnd) /*there is not a interval in between these numbers*/
            {
                cnt++;
                prev=points[i];
            }

            else
            {/*overllaping region */
                prev[0] = max(prevStart, currStart);
                prev[1] = min(prevEnd, currEnd);
            }
        }
        return cnt;
    }
};