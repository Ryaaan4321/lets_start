#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        int n = pl.size();
        int m = tr.size();
        sort(pl.begin(),pl.end());
        sort(tr.begin(),tr.end());

        int i = 0;
        int j = 0;
        int cnt = 0;
        while (i < n && j < m) {
            if (tr[j] > pl[i]) {
                i++;
                j++;
                cnt++;
            } else if(tr[j]==pl[i]) {
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};