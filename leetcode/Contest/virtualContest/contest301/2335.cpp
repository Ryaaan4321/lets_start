#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &a)
    {
        priority_queue<int>pq;
        for(auto x:a){
            if(x){
                pq.push(x);
            }
        }
        int ans=0;
        while (pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a>1){
                pq.push(a--);
            }
            if(b>1){
                pq.push(b--);

            }
            ans++;
            /* code */
        }
        return (pq.empty()?ans:ans+pq.top());
        
    }
};