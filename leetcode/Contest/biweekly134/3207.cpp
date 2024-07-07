#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a) {
        int n = a.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            a.push_back(a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == a[i + 2] and a[i] != a[i + 1]) {
                c++;
            }
        }
        return c;
    }
};