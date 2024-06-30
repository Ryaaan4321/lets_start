#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool check(string s, string t)
    {
        bool f=1;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < t.length(); j++)
            {
                if (s[i] != t[j])
                {
                    f=0;
                }
            }
        }
        return (f==1?1:0);
    }
    int st(vector<string> &w, string t, int idx)
    {
        int ans = -1;
        for (int i = 0; i < w.size(); i++)
        {
            if (check(w[i], t))
            {
                ans = idx - i;
            }
        }
        return ans;
    }
    int end(vector<string> &wd, string t, int idx)
    {
        int ans=-1;
        for(int i=wd.size()-1;i>=0;i--){
            if(check(wd[i],t)){
                ans=idx-i;
            }
        }
        return ans;
    }
    int closetTarget(vector<string> &w, string t, int startIndex)
    {
        int a1=st(w,t,startIndex);
        int a2=end(w,t,startIndex);
        return min(a1,a2);

    }
};