#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

/*you gotta be almost insane to your craft - sir mc-gregor*/

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        const int n=logs.size();
        pair<int,int> p[500];
        for(int i=0;i<logs.size();i++){
            for(int j=0;j<1;j++){
                p->first=logs[i][0];
                p->second=logs[i][1];
            }
        }
        sort(p, p + n,[](const pair<int, int>& a, const pair<int, int>& b) -> bool {
                return a.first > b.first;
        });
        int mx=INT_MIN;
        for(auto it:p){
            if(it.second>mx){
                mx=it.second;
            }
        }
        
    }
};