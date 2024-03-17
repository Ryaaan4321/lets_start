#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> lost_map;
        for (auto it : matches)
        {
            int lose = it[1];
            lost_map[lose]++;
        }
        vector<int> not_lost;
        vector<int> lost_once;

        for (auto it : matches)
        {
            int winner = it[0];
            int lost = it[1];

            if (lost_map.find(winner) == lost_map.end())
            {
                not_lost.push_back(winner);
                lost_map[winner] = 2;
            }
            if (lost_map[lost] == 1)
            {
                lost_once.push_back(lost);
            }
        }
        sort(begin(not_lost),end(not_lost));
        sort(begin(lost_once),end(lost_once));

        return {not_lost,lost_once};
    }
    
};