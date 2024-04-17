#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    long long taskSchedulerII(vector<int> &a, int space)
    {
        map<long long, long long> last;
        long long day = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (last.find(a[i]) == last.end())
            {
                day++;
                last[a[i]] = day;
                continue;
            }
            long long last_date = last[a[i]];
            day = max(day+1, last_date + space + 1);
            last[a[i]]=day;
        }
        return day;
    }
};