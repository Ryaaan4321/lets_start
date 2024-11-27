#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            adj[i].push_back(i + 1);
        }
        auto shortestpath = [&]() {
            queue<pair<int, int>> q;
            set<int> st;
            q.push({0, 0});
            st.insert(0);
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                int curnode = node.first;
                int cnt = node.second;
                if (curnode == n - 1) {
                    return cnt;
                }
                for (int ad : adj[curnode]) {
                    if (st.find(ad) == st.end()) {
                        q.push({ad, cnt + 1});
                        st.insert(ad);
                    }
                }
            }
            return -1;
        };
        vector<int> res;
        for (const auto& query : queries) {
            adj[query[0]].push_back(query[1]);
            res.push_back(shortestpath());
        }
        return res;
    }
};