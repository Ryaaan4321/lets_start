#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int> travel) {
        int time = 0;
        int n = garbage.size();
        int m = 0;
        int p = 0;
        int g = 0;
        /*
        for (int j = 0; j < garbage[i].length(); j++) /
        */
        for (int i = 0; i < n; i++) {
            for(int j=0;j<garbage[i].length();j++) {
                if (garbage[i][j] == 'M') {
                    m = i;
                } else if (garbage[i][j] == 'P') {
                    p = i;
                } else {
                    g = i;
                }
                time++;
            }
        }

        for (int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i - 1];
        }
        time += m > 0 ? travel[m - 1] : 0;
        time += g > 0 ? travel[g - 1] : 0;
        time += p > 0 ? travel[p - 1] : 0;
        return time;
    }
};