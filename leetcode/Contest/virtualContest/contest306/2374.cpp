#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        int n=edges.size();
        vector<long long> indegree(n+2);
        for(int i=0;i<n;i++){
            indegree[edges[i]]+=i;
        }
        int max_elm=indegree[0];
        int idx=0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]>max_elm){
                max_elm=indegree[i];
                idx=i;
            }
        }
        return idx;
    }
};