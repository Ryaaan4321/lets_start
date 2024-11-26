#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for (auto it : edges) {
            indegree[it[1]]++;
        }
        vector<int> cnt;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                cnt.push_back(i);
            }
        }
        return cnt.size() != 1 ? -1 : cnt[0];
    }
};