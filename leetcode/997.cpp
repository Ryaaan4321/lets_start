#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {

        vector<int> indegree(n + 1);
        vector<int> outdegree(n + 1);
        for (vector<int> vec : trust)
        {
            int u = vec[0];
            int v = vec[1];

            outdegree[u]++;
            indegree[v]++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (indegree[i] == n - 1 && outdegree[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
    int findJudge1(int n, vector<vector<int>> &trust)
    {
        vector<int> cnt;

        for (vector<int> vec : trust)
        {
            int u = vec[0];
            int v = vec[1];

            cnt[u]--;
            cnt[v]++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (cnt[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};